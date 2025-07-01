#pragma once

class SceneBase
{
public:
	SceneBase();	//�R���X�g���N�^
	virtual ~SceneBase() = 0;	//�f�X�g���N�^

	//������
	virtual void Init(void) = 0;

	//�ǂݍ���
	virtual void Load(void) = 0;

	//�ǂݍ��݌�
	virtual void LoadEnd(void) = 0;

	//�X�V
	virtual void Update(void) = 0;

	//�`��
	virtual void Draw(void) = 0;

	//�������
	virtual void Release(void) = 0;
};
