#pragma once
#include <DxLib.h>

class Camera
{
public:
	// �V���O���g���i�����E�擾�E�폜�j
	static void CreateInstance(void) { if (instance_ == nullptr) { instance_ = new Camera(); } };
	static Camera* GetInstance(void) { return instance_; };
	static void DeleteInstance(void) { if (instance_ != nullptr) { delete instance_; instance_ = nullptr; } }
private:
	Camera();	//�C���X�g���N�^
	~Camera();	//�f�X�g���N�^

	//�ÓI�C���X�^���X
	static Camera* instance_;
public:
	//�萔

	//�J�����̏����ʒu
	static constexpr VECTOR INIT_POS = { 0.0f, 1000.0f, -1000.0f };

	//�J�����̏����p�x
	static constexpr VECTOR INIT_ANGLE = {
		DX_PI_F / 180.0f * 30.0f,
		0.0f,
		0.0f
	};

	//�J�����N���b�v: NEAR
	static constexpr float CAMERA_NEAR = 3.0f;

	//�J�����N���b�v : FAR
	static constexpr float CAMERA_FAR = 5000.0f;

	//�J�����X�s�[�h�i�ړ��j
	static constexpr float MOVE_SPEED = 10.0f;

	//�J�����X�s�[�h�i�p�x�j
	static constexpr float ANGLE_SPEED = 1.0f;

	void Init(void);
	void Update(void);
	void SetBeforeDraw(void);
	void DebugDraw(void);
	void Release(void);

	//�Ǐ]������W
	void SetFollowPos(VECTOR pos);

private:

	//�J�����̒Ǐ]�Ώۂ̈ʒu
	VECTOR followPos_;

	//�J�����̍��W
	VECTOR pos_;

	//�J�����̊p�x
	VECTOR angle_;
};