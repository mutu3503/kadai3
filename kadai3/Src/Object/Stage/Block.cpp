#include "Block.h"

Block::Block()
{
}

Block::~Block()
{
}

void Block::Create(TYPE type, int modelId, int mapX, int mapZ)
{
	// �u���b�N�̎�ސݒ�
	type_ = type;

	// ���f���̕���
	modelId_ = MV1DuplicateModel(modelId);

	// ���Ȕ���
	MV1SetMaterialEmiColor(modelId_, 0, EMI_COLOR);

	// �傫���ݒ�
	scale_ = SCALE;
	MV1SetScale(modelId_, scale_);

	// 1�u���b�N�̔����̑傫��
	const float HALF_BLOCK_SIZE = SIZE * 0.5f;

	// �����Ŏw�肳�ꂽ�}�b�v���W������W���v�Z����
	// 3D���f���̒��S���W�́A�u���b�N�̒��S
	float x = static_cast<float>(mapX);
	float z = static_cast<float>(mapZ);

	// ���W�̐ݒ�
	pos_ = VGet(
		(SIZE * x) + HALF_BLOCK_SIZE,
		-HALF_BLOCK_SIZE,
		(SIZE * z) + HALF_BLOCK_SIZE
	);
	MV1SetPosition(modelId_, pos_);
}

void Block::Update(void)
{
}

void Block::Draw(void)
{
	// ���f���̕`��
	MV1DrawModel(modelId_);
}

void Block::Release(void)
{
	// ���f���̉��
	MV1DeleteModel(modelId_);
}