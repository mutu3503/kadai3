#pragma once
#include<DxLib.h>
#include "Block.h"

class Stage
{
public:
	static constexpr int BLOCK_MODEL_NUM = static_cast<int>(Block::TYPE::MAX);

	static constexpr int BLOCK_NUM_X = 20;
	static constexpr int BLOCK_NUM_Z = 20;

public:
	Stage();
	~Stage();

	void Init(void);      //初期化
	void Load(void);      //読み込み
	void LoadEnd(void);   //読み込み後
	void Update(void);
	void Draw(void);
	void Release(void);

private:
	//マップデータの読み込み
	void LoadMapCsvData(void);

private:

	//ブロックのオリジナルハンドル
	int blockOriginModelId_[BLOCK_MODEL_NUM];

	//ブロッククラス
	Block* blocks_[BLOCK_NUM_Z][BLOCK_NUM_X];
};