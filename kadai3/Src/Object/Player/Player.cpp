#include "Player.h"
#include"../../Utility/AsoUtility.h"
#include"../../Input/InputManager.h"
#include"../../Camera/Camera.h"

Player::Player()
{
}

Player::~Player()
{
}

void Player::Init(void)
{
	//���f���̑傫��
	scale_ = SCALE;
	MV1SetScale(modelId_, scale_);

	//���f���̊p�x
	angle_ = AsoUtility::VECTOR_ZERO;
	MV1SetRotationXYZ(modelId_, angle_);

	//���f���̍��W
	pos_ = INIT_POS;
	MV1SetPosition(modelId_, pos_);

	//���Ȕ���
	MV1SetMaterialAmbColor(modelId_, 0, EMI_COLOR);

	//�A�j���[�V����
	prevAnimType_ = ANIM_TYPE::IDLE;
	nowAnimType_ = ANIM_TYPE::IDLE;
	attachNo_ = 0;
	nowAnimTime_ = 0;
	totalAnimTime_ = 0;
}


void Player::Load(void)
{
	//���f���̃��[�h
	modelId_ = MV1LoadModel("Data/Model/Player/Player.mv1");
}

void Player::LoadEnd(void)
{
	//������
	Init();

	//�A�j���[�V�����̏�����
	attachNo_ = MV1AttachAnim(modelId_, static_cast<int>(nowAnimType_));

	//�A�j���[�V�����̑��Đ����Ԃ��擾
	totalAnimTime_ = MV1GetAttachAnimTotalTime(modelId_, attachNo_);
}

void Player::Update(void)
{
	//�ړ�����
	ProcessMove();

	//�A�j���[�V�����̍X�V
	UpdataAnim();

	//�J�����ɍ��W��n��
	Camera::GetInstance()->SetFollowPos(pos_);
}

void Player::Draw(void)
{
	//���f���`��
	MV1DrawModel(modelId_);
}

void Player::Release(void)
{
	//���f���̍폜
	MV1DeleteModel(modelId_);
}

void Player::ProcessMove(void)
{
	//�ړ�����
	VECTOR moveDir = AsoUtility::VECTOR_ZERO;

	//�����
	if (InputManager::GetInstance()->IsNew(KEY_INPUT_W))
	{
		moveDir = AsoUtility::DIR_F;
	}
	//������
	if (InputManager::GetInstance()->IsNew(KEY_INPUT_S))
	{
		moveDir = AsoUtility::DIR_B;
	}
	//������
	if (InputManager::GetInstance()->IsNew(KEY_INPUT_A))
	{
		moveDir = AsoUtility::DIR_L;
	}
	//�E����
	if (InputManager::GetInstance()->IsNew(KEY_INPUT_D))
	{
		moveDir = AsoUtility::DIR_R;
	}

	//�ړ����Ă�����
	if (!AsoUtility::EqualsVZero(moveDir))
	{
		//���f���̈ړ�������Y����]������
		//�������p�x(���W�A��)�ɕϊ�����
		angle_.y = atan2(moveDir.x, moveDir.z);

		//���f�������f���Ă���̂ŋ����I�ɉ�]������
		angle_.y += AsoUtility::Deg2RadF(180.0f);

		//���f���ɉ�]��ݒ肷��
		MV1SetRotationXYZ(modelId_, angle_);

		//�ړ��ʂ��v�Z����(����*�X�s�[�h)
		VECTOR movePow = VScale(moveDir,MOVE_SPEED);

		//�ړ�����(���W+�ړ���)
		pos_= VAdd(pos_,movePow);

		//���f���ɍ��W��ݒ肷��
		MV1SetPosition(modelId_,pos_);

		//�A�j���[�V������ύX����
		nowAnimType_ = ANIM_TYPE::WALK;
	}
	else
	{
		//�ړ����Ă��Ȃ�

		//�A�j���[�V������ύX����
		nowAnimType_ = ANIM_TYPE::IDLE;
	}
}

void Player::UpdataAnim(void)
{
	//�A�j���[�V�������ύX���ꂽ�H
	if (prevAnimType_ != nowAnimType_)
	{
		//�A�j���[�V������ʂ����킹��
		prevAnimType_ = nowAnimType_;

		//���f������O��̃A�j���[�V�������O��
		MV1DetachAnim(modelId_, attachNo_);

		//�A�j���[�V������ύX����
		attachNo_ = MV1AttachAnim(modelId_, static_cast<int>(nowAnimType_));

		//�A�j���[�V�����̑��Đ����Ԃ��擾
		totalAnimTime_ = MV1GetAttachAnimTotalTime(modelId_, attachNo_);

		//�A�j���[�V�������Ԃ�������
		nowAnimTime_ = 0.0f;
	}

	//�A�j���[�V�����̎��Ԃ�i�߂�
	nowAnimTime_ += 1.0f;

	//�A�j���[�V���������[�v
	if (nowAnimTime_ > totalAnimTime_)
	{
		nowAnimTime_ = 0.0f;
	}

	//�A�j���[�V�����̐ݒ�
	MV1SetAttachAnimTime(modelId_, attachNo_, nowAnimTime_);
}
