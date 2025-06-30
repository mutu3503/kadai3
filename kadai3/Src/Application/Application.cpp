#include <DxLib.h>
#include "Application.h"
#include "../FpsControl/FpsControl.h"

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

	// FPS������
	fps_ = new FpsControl;
	fps_->Init();
}

// �Q�[�����[�v
void Application::Run(void)
{
	//TitleEdit editor;
	//editor.Init();

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

		fps_->CalcFrameRate();	// �t���[�����[�g�v�Z
		fps_->DrawFrameRate();	// �t���[�����[�g�`��

		ScreenFlip();
	}
}

// ���
void Application::Release(void)
{
	// �t���[�����[�g���
	delete fps_;

	// DxLib�I��
	if (DxLib_End() == -1)
	{
		isReleaseFail_ = true;
	}
}
