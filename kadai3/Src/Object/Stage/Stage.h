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

	void Init(void);      //������
	void Load(void);      //�ǂݍ���
	void LoadEnd(void);   //�ǂݍ��݌�
	void Update(void);
	void Draw(void);
	void Release(void);

private:
	//�}�b�v�f�[�^�̓ǂݍ���
	void LoadMapCsvData(void);

private:

	//�u���b�N�̃I���W�i���n���h��
	int blockOriginModelId_[BLOCK_MODEL_NUM];

	//�u���b�N�N���X
	Block* blocks_[BLOCK_NUM_Z][BLOCK_NUM_X];
};