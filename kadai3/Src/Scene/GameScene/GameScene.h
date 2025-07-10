#pragma once
#include"../SceneBase.h"
#include "../../Object/Player/Player.h"

//�N���X�̑O���錾
class Grid;
class Stage;
class Player;

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

private:
	Grid* grid_;		//�O���b�h�N���X�i�f�o�b�N�p�j

	Stage* stage_;		//�X�e�[�W�N���X
	Player* player_;     //�v���C���N���X
};