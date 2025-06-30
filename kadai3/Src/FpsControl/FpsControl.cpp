#include <DxLib.h>
#include "FpsControl.h"
#include "../Application/Application.h"

// �R���X�g���N�^
FpsControl::FpsControl()
	: currentTime(0)
	, prevFrameTime(0)
	, frameCnt(0)
	, updateFrameRateTime(0)
	, frameRate(0.0f)
{
}

// �f�X�g���N�^
FpsControl::~FpsControl()
{
}

// ������
void FpsControl::Init(void)
{
	currentTime = 0;
	prevFrameTime = 0;
	frameCnt = 0;
	updateFrameRateTime = 0;
	frameRate = 0.0f;
}

// �t���[�����[�g�X�V
bool FpsControl::UpdateFrameRate(void)
{
	Sleep(1);	// �V�X�e���ɏ�����Ԃ�

	// ���݂̎������擾
	currentTime = GetNowCount();

	// ���݂̎������A�O��̃t���[�����s�����
	// 1/60�b�o�߂��Ă����珈�������s����
	if (currentTime - prevFrameTime >= FRAME_RATE)
	{
		// �t���[�����s���̎��Ԃ��X�V
		prevFrameTime = currentTime;

		// �t���[�������J�E���g
		frameCnt++;

		// 1/60�o�߂���
		return true;
	}

	return false;
}

// �t���[�����[�g�v�Z
void FpsControl::CalcFrameRate()
{
	// �O��̃t���[�����[�g�X�V����̌o�ߎ��Ԃ����߂�
	int difTime = currentTime - updateFrameRateTime;

	// �O��̃t���[�����[�g���X�V����
	// 1�b�ȏ�o�߂��Ă�����t���[�����[�g���X�V����
	if (difTime > 1000)
	{
		// �t���[���񐔂��~���b�ɍ��킹��
		// �����܂ŏo�����̂�float�ɃL���X�g
		float castFrameCnt = (float)(frameCnt * 1000);

		// �t���[�����[�g�����߂�
		// ���z�ʂ�Ȃ� 60000 / 1000 �� 60 �ƂȂ�
		frameRate = castFrameCnt / difTime;

		// �t���[���J�E���g���N���A
		frameCnt = 0;

		// �t���[�����[�g�X�V���Ԃ��X�V
		updateFrameRateTime = currentTime;
	}
}

// �t���[�����[�g��\��(�f�o�b�O�p)
void FpsControl::DrawFrameRate()
{
	// �X�N���[���̉E�[�ɗ���悤�ɐݒ�
	DrawFormatString(
		Application::SCREEN_SIZE_X - 90,
		0,
		0xFF0000,
		"FPS[%.2f]",
		frameRate
	);
}
