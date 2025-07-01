#include"Loading.h"
#include<DxLib.h>
#include"../Application/Application.h"

Loading* Loading::instance_ = nullptr;

//�Œ�ł����[�h��ʂ�\�����鎞��
static constexpr int MIN_LOAD_TIME = 60;		//60fps(1�b)

Loading::Loading() {};
Loading::~Loading() {};

void Loading::Init(void)
{
	loadTimer_ = 0;
	isLoading_ = false;

	//��ʒ����Ɏ����Ă���
	posX_ = Application::SCREEN_SIZE_X / 2;
	posY_ = Application::SCREEN_SIZE_Y / 2;
}

void Loading::Load(void)
{
	handle_ = LoadGraph("Data/Image/Axe.png");
}

void Loading::Update(void)
{
	loadTimer_++;

	//�ǂݍ��ݒ��̂��̂��Ȃ��Ȃ�����
	if (GetASyncLoadNum() == 0 && loadTimer_ >= MIN_LOAD_TIME)
	{
		//���[�h�I��
		Init();
	}
	//�ǂݍ��ݒ�
	else
	{
		//���[�h��ʂŗV�т�����Ȃ炱���ɋL�q
	}
}

void Loading::Draw(void)
{
	DrawRotaGraph(
		posX_, posY_,	//���W
		1.0,			//�g��l
		0.0,			//��]�l
		handle_,		//�摜�n���h��
		true			//���߃t���O
	);
}

void Loading::Release(void)
{
	DeleteGraph(handle_);
}

void Loading::StartAsyncLoad(void)
{
	isLoading_ = true;
	SetUseASyncLoadFlag(true);
}

void Loading::EndAsyncLoad(void)
{
	SetUseASyncLoadFlag(false);
}

bool Loading::IsLoading(void)
{
	return isLoading_;
}
