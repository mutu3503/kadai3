#include "UIButton.h"

#include <DxLib.h>
#include "../Collision/Collision.h"

UIButton::UIButton(int posX, int posY, int sizeW, int sizeH)
{
	posX_ = posX;
	posY_ = posY;

	sizeW_ = sizeW;
	sizeH_ = sizeH;

	buttonState_ = BUTTON_STATE::DISABLED;
}

UIButton::~UIButton()
{
}

void UIButton::Init(void)
{
	handle_[(int)BUTTON_STATE::DEFAULT] = LoadGraph("Data/Image/Button/s_001.png");
	handle_[(int)BUTTON_STATE::HOVER] = LoadGraph("Data/Image/Button/s_001_hover.png");
	handle_[(int)BUTTON_STATE::DISABLED] = LoadGraph("Data/Image/Button/s_001_click.png");
}

void UIButton::Update(void)
{
	// �}�E�X�̍��W���擾
	int mousePosX = 0;
	int mousePosY = 0;

	GetMousePoint(&mousePosX, &mousePosY);

	// �f�t�H���g���
	buttonState_ = BUTTON_STATE::DEFAULT;

	// �{�^���̏�Ƀ}�E�X�|�C���^�����邩�H
	if (CollCheckPointRect(posX_, posY_, sizeW_, sizeH_, mousePosX, mousePosY))
	{
		// �{�^���̏�Ƀ}�E�X�|�C���^������
		buttonState_ = BUTTON_STATE::HOVER;

		// �N���b�N����Ă���̂��H
		if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0)
		{
			// �N���b�N����Ă���
			buttonState_ = BUTTON_STATE::DISABLED;
		}
	}
}

void UIButton::Draw(void)
{
	// �`��
	DrawRotaGraph(
		posX_, posY_,				// ���W
		1.0,						// �g��l
		0.0,						// ��]�l
		handle_[(int)buttonState_],	// �摜�n���h��
		true						// ���߃t���O
	);
}

void UIButton::Delete(void)
{
	// �폜
	for (int i = 0; i < (int)BUTTON_STATE::BUTTON_STATE_MAX; i++)
	{
		DeleteGraph(handle_[i]);
	}
}

BUTTON_STATE UIButton::GetButtonState(void)
{
	return buttonState_;
}
