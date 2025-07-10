#pragma once
#include <DxLib.h>

class Block
{
public:
	// �u���b�N���
	enum class TYPE
	{
		NONE = -1,	// �����Ȃ�
		GRASS,		// ��
		METAL,		// ����
		ICE,		// �X

		MAX			// �S��ʐ�
	};

	// �萔
	// ���Ȕ����F
	static constexpr COLOR_F EMI_COLOR = { 0.5f,0.5f,0.5f,1.0f };

	// ���f���̑傫��
	static constexpr VECTOR SCALE = { 0.5f,0.5f,0.5f };

	// 1�u���b�N������̃T�C�Y
	static constexpr float SIZE = 100.0f;

public:
	Block();
	~Block();

	// �u���b�N�𐶐�����
	void Create(TYPE type, int modelId, int mapX, int mapZ);
	void Update(void);	// �X�V
	void Draw(void);	// �`��
	void Release(void);	// ���

private:

	TYPE type_;		// �u���b�N���
	int modelId_;	// ���f����ID
	VECTOR pos_;	// ���W
	VECTOR scale_;	// �傫��
};