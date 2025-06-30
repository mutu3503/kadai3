#pragma once

// �t���[�����[�g
static constexpr float FRAME_RATE(1000 / 60);

class FpsControl
{
public:

	FpsControl();	// �R���X�g���N�^
	~FpsControl();	// �f�X�g���N�^

public:
	// ������
	void Init(void);

	// �t���[�����[�g�X�V
	bool UpdateFrameRate(void);

	// �t���[�����[�g�v�Z
	void CalcFrameRate(void);

	// �t���[�����[�g�\�� (�f�o�b�O�\��)
	void DrawFrameRate(void);

private:

	int currentTime;			// ���݂̎���
	int prevFrameTime;			// �O��̃t���[�����s���̎���

	int frameCnt;				// �t���[���J�E���g�p
	int updateFrameRateTime;	// �t���[�����[�g���X�V��������

	float frameRate;			// �t���[�����[�g (�\���p)
};
