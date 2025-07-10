#pragma once
#include<DxLib.h>


class Player
{
public:
	//�A�j���[�V�������
	enum class ANIM_TYPE
	{
		DEAD = 0,	//���S
		IDLE = 3,	//�ҋ@
		WALK = 14,	//���s
	};

public:
	//���f���̑傫��
	static constexpr VECTOR SCALE = { 0.5f,0.5f,0.5f };
	//�����ʒu
	static constexpr VECTOR INIT_POS = { 300.0f,10.0f,300.0f };
	//���Ȕ���
	static constexpr COLOR_F EMI_COLOR = { 0.5f,0.5f,0.5f,0.5f };
	//�ړ��X�s�[�h
	static constexpr float MOVE_SPEED = 10.0f;

public:
	Player();
	~Player();

	void Init(void);
	void Load(void);
	void LoadEnd(void);
	void Update(void);
	void Draw(void);
	void Release(void);

private:
	//�ړ�����
	void ProcessMove(void);

	//�A�j���[�V�����X�V
	void UpdataAnim(void);
private:
	int modelId_;	//���f���n���h��
	VECTOR pos_;	//���W
	VECTOR angle_;	//����
	VECTOR scale_;	//�傫��

	//�A�j���[�V����
	ANIM_TYPE prevAnimType_;	//�O��̃A�j���[�V����
	ANIM_TYPE nowAnimType_;		//���݂̃A�j���[�V����

	int attachNo_;         //�A�^�b�`No 
	float nowAnimTime_;    //�Đ����̎���
	float totalAnimTime_;   //���Đ�����
};
