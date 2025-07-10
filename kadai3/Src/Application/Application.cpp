#include <DxLib.h>
#include "Application.h"
#include "../FpsControl/FpsControl.h"
#include"../Scene/SceneManager/SceneManager.h"
#include"../Input/InputManager.h"

Application* Application::instance_ = nullptr;

// �R���X�g���N�^
Application::Application(void)
{
	isInitFail_ = false;
	isReleaseFail_ = false;
	fps_ = nullptr;
}

// �f�X�g���N�^
Application::~Application(void)
{
}

// ������
void Application::Init(void)
{
	// �A�v���P�[�V�����̏����ݒ�
	SetWindowText("Kadai3");

	// �E�B���h�E�֘A
	SetGraphMode(SCREEN_SIZE_X, SCREEN_SIZE_Y, 32);	// �T�C�Y�ύX
	ChangeWindowMode(true);	// false = �t���X�N���[��

	// DxLib�̏�����
	SetUseDirect3DVersion(DX_DIRECT3D_11);
	isInitFail_ = false;
	if (DxLib_Init() == -1)
	{
		// ���������s
		isInitFail_ = true;
		return;
	}

	// �`����ʂ𗠂ɂ���
	SetDrawScreen(DX_SCREEN_BACK);

	// �L�[���䏉����
	SetUseDirectInputFlag(true);	
	InputManager::CreateInstance();
	InputManager::GetInstance()->Init();

	//�V�[���Ǘ�������
	SceneManager::CreateInstance();
	SceneManager::GetInstance()->Init();

	// FPS������
	fps_ = new FpsControl;
	fps_->Init();
}

// �Q�[�����[�v
void Application::Run(void)
{
	// �Q�[�����[�v
	while (ProcessMessage() == 0)
	{
		// �G�X�P�[�v�L�[�������ꂽ��Q�[���I��
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1) return;

		// �t���[�����[�g�X�V
		// 1/60�b�o�߂��Ă��Ȃ��Ȃ�ă��[�v������
		if (!fps_->UpdateFrameRate()) continue;

		// ��ʂ�������
		ClearDrawScreen();

		InputManager::GetInstance()->Update();	//���͐���X�V

		SceneManager::GetInstance()->Update();	//�V�[���̍X�V
		SceneManager::GetInstance()->Draw();	//�V�[���̕`��

		fps_->CalcFrameRate();	// �t���[�����[�g�v�Z
		fps_->DrawFrameRate();	// �t���[�����[�g�`��

		ScreenFlip();
	}
}

// ���
void Application::Release(void)
{
	//���͐���폜
	InputManager::DeleteInstance();

	//�V�[���̊Ǘ�����E�폜
	SceneManager::GetInstance()->Release();
	SceneManager::DeleteInstance();

	// �t���[�����[�g���
	delete fps_;

	// DxLib�I��
	if (DxLib_End() == -1)
	{
		isReleaseFail_ = true;
	}
}
