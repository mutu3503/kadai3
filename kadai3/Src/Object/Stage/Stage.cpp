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
	//�e��u���b�N�̃I���W�i�����[�h
	blockOriginModelId_[0]
		= MV1LoadModel("Data/Model/Blocks/Block_Grass.mv1");
	blockOriginModelId_[1]
		= MV1LoadModel("Data/Model/Blocks/Block_Metal.mv1");
	blockOriginModelId_[2]
		= MV1LoadModel("Data/Model/Blocks/Block_Ice.mv1");

	//�}�b�v�ǂݍ���
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
	//�u���b�N�̕`��
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
	//�u���b�N�̍폜
	for (int z = 0; z < BLOCK_NUM_Z; z++)
	{
		for (int x = 0; x < BLOCK_NUM_X; x++)
		{
			blocks_[z][x]->Release();
			delete blocks_[z][x];
		}
	}

	//�I���W�i�����f���̍폜
	for (int i = 0; i < BLOCK_MODEL_NUM; i++)
	{
		MV1DeleteModel(blockOriginModelId_[i]);
	}
}

void Stage::LoadMapCsvData(void)
{
	//�t�@�C���̓ǂݍ���
	std::ifstream ifs = std::ifstream("Data/MapData/MapData.csv");

	//�t�@�C���̓ǂݍ��݂��������Ă��邩
	if (!ifs)
	{
		//�G���[������
		return;
	}

	//�t�@�C�����P�s���ǂݍ���
	std::string line;					//1�s�̕������
	std::vector<std::string> strSplit;	//1�s��1�����̓��I�z��ɕ���

	int mapNo = 0;	//�}�b�v���
	int z = 0;

	//�t�@�C�������ׂēǂݍ��ނ܂�
	while (getline(ifs,line))
	{
		//1�s���J���}��؂�ŕ���
		strSplit = AsoUtility::Split(line,',');

		//1�s�ǂݍ��ނ܂�
		for (int x = 0; x < strSplit.size(); x++)
		{
			//�����񂩂琮���ɕϊ�
			//string����int�ɕϊ�
			mapNo = stoi(strSplit[x]);

			//�}�b�v�^�C�v���L���X�g
			Block::TYPE type = static_cast<Block::TYPE>(mapNo);

			//�I���W�i���̃��f�������
			int baseModel = blockOriginModelId_[mapNo];

			//�u���b�N�𐶐�
			Block* block = new Block();
			block->Create(type, baseModel, x, z);

			//2�����z��Ƀu���b�N���i�[
			blocks_[z][x] = block;
		}
		z++;
	}

}
