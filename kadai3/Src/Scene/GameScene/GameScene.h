#pragma once
#include"../SceneBase.h"

//�x�[�X���p��
class GameScene : public SceneBase	
{
public:
	GameScene();						//�R���X�g���N�^
	~GameScene()			override;	//�f�X�g���N�^

	void Init(void)			override;	//������
	void Load(void)			override;	//�ǂݍ���
	void LoadEnd(void)		override;	//�ǂݍ��݌�
	void Update(void)		override;	//�X�V
	void Draw(void)			override;	//�`��
	void Release(void)		override;	//���
};