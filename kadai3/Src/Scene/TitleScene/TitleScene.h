#pragma once
#include"../SceneBase.h"

//�x�[�X���p��
class TitleScene : public SceneBase
{
public:
	TitleScene(void);			//�R���X�g���N�^
	~TitleScene(void) override;	//�f�X�g���N�^

	void Init(void) override;		//������
	void Load(void) override;		//�ǂݍ���
	void LoadEnd(void) override;	//�ǂݍ��݌�
	void Update(void) override;		//�X�V
	void Draw(void) override;		//�`��
	void Release(void) override;	//���
};

