#include "Stage.h"
#include "../../Utility/AsoUtility.h"
#include <fstream>

Stage::Stage()
{
}

Stage::~Stage()
{
}

void Stage::Init(void)
{
}

void Stage::Load(void)
{
	//各種ブロックのオリジナルロード
	blockOriginModelId_[0]
		= MV1LoadModel("Data/Model/Blocks/Block_Grass.mv1");
	blockOriginModelId_[1]
		= MV1LoadModel("Data/Model/Blocks/Block_Metal.mv1");
	blockOriginModelId_[2]
		= MV1LoadModel("Data/Model/Blocks/Block_Ice.mv1");

	//マップ読み込み
	LoadMapCsvData();
}

void Stage::LoadEnd(void)
{
}

void Stage::Update(void)
{
}

void Stage::Draw(void)
{
	//ブロックの描画
	for (int z = 0; z < BLOCK_NUM_Z; z++)
	{
		for (int x = 0; x < BLOCK_NUM_X; x++)
		{
			blocks_[z][x]->Draw();
		}
	}
}

void Stage::Release(void)
{
	//ブロックの削除
	for (int z = 0; z < BLOCK_NUM_Z; z++)
	{
		for (int x = 0; x < BLOCK_NUM_X; x++)
		{
			blocks_[z][x]->Release();
			delete blocks_[z][x];
		}
	}

	//オリジナルモデルの削除
	for (int i = 0; i < BLOCK_MODEL_NUM; i++)
	{
		MV1DeleteModel(blockOriginModelId_[i]);
	}
}

void Stage::LoadMapCsvData(void)
{
	//ファイルの読み込み
	std::ifstream ifs = std::ifstream("Data/MapData/MapData.csv");

	//ファイルの読み込みが成功しているか
	if (!ifs)
	{
		//エラーが発生
		return;
	}

	//ファイルを１行ずつ読み込む
	std::string line;					//1行の文字情報
	std::vector<std::string> strSplit;	//1行を1文字の動的配列に分割

	int mapNo = 0;	//マップ情報
	int z = 0;

	//ファイルをすべて読み込むまで
	while (getline(ifs,line))
	{
		//1行をカンマ区切りで分割
		strSplit = AsoUtility::Split(line,',');

		//1行読み込むまで
		for (int x = 0; x < strSplit.size(); x++)
		{
			//文字列から整数に変換
			//stringからintに変換
			mapNo = stoi(strSplit[x]);

			//マップタイプをキャスト
			Block::TYPE type = static_cast<Block::TYPE>(mapNo);

			//オリジナルのモデルを取る
			int baseModel = blockOriginModelId_[mapNo];

			//ブロックを生成
			Block* block = new Block();
			block->Create(type, baseModel, x, z);

			//2次元配列にブロックを格納
			blocks_[z][x] = block;
		}
		z++;
	}

}
