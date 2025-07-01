#include "SceneManager.h"

#include<DxLib.h>
#include"../TitleScene/TitleScene.h"
#include"../GameScene/GameScene.h"

SceneManager* SceneManager::instance_ = nullptr;

SceneManager::SceneManager(void) {}
SceneManager::~SceneManager(void) {}

void SceneManager::Init(void)
{
	Init3D();

	//�ŏ��̓^�C�g���V�[������
	ChangeScene(SCENE_ID::TITLE);
}

void SceneManager::Init3D(void)
{
	//�w�i�F�ݒ�
	SetBackgroundColor(0, 0, 0);

	//Z�o�b�t�@��L���ɂ���
	SetUseZBuffer3D(true);

	//Z�o�b�t�@�ւ̏������݂�L���ɂ���
	SetWriteZBuffer3D(true);

	//�o�b�N�J�����O��L���ɂ���
	SetUseBackCulling(true);

	//���C�g�̐ݒ�
	SetUseLighting(true);

	//���ʂ���΂߉��Ɍ����������C�g
	ChangeLightTypeDir({ 0.0f,-1.0f,1.0f });
}

void SceneManager::Update(void)
{
	//���݂̃V�[�����X�V
	scene_->Update();
}

void SceneManager::Draw(void)
{
	//���݂̃V�[����`��
	scene_->Draw();
}

void SceneManager::Release(void)
{
	//���݂̃V�[��������E�폜
	scene_->Release();
	delete scene_;
}

void SceneManager::ChangeScene(SCENE_ID nextId)
{
	//�V�[����ύX����
	sceneId_ = nextId;

	//���݂̃V�[�������
	if (scene_ != nullptr)
	{
		scene_->Release();	//���݂̃V�[�������
		delete scene_;		//�V�[���̍폜
	}

	//�e�V�[���ɐ؂�ւ�
	switch (sceneId_)
	{
	case SceneManager::SCENE_ID::NONE:
		break;
	case SceneManager::SCENE_ID::TITLE:
		scene_ = new TitleScene();
		break;
	case SceneManager::SCENE_ID::GAME:
		scene_ = new GameScene();
		break;
	default:
		break;
	}

	//������
	scene_->Init();
	scene_->Load();
}
