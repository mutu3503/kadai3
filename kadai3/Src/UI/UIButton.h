#pragma once


// �{�^���̏��
enum class BUTTON_STATE
{
	DEFAULT,	// �ʏ�
	HOVER,		// �N���b�N�\
	DISABLED,	// �N���b�N�s��

	BUTTON_STATE_MAX,	// ��Ԃ̍ő吔
};

class UIButton
{
public:
	// �R���X�g���N�^
	// �������ɍ��W�E�T�C�Y��ݒ�\
	UIButton(int posX, int posY, int sizeW, int sizeH);

	// �f�X�g���N�^
	~UIButton();

	void Init(void);	// ������
	void Update(void);	// �X�V
	void Draw(void);	// �`��
	void Delete(void);	// �폜

	// �{�^���̏�Ԃ�Ԃ�
	BUTTON_STATE GetButtonState(void);

private:
	BUTTON_STATE buttonState_;	// �{�^���̏��

	// �{�^���̉摜�n���h��
	int handle_[(int)BUTTON_STATE::BUTTON_STATE_MAX];

	int posX_;	// X���W
	int posY_;	// Y���W

	int sizeW_;	// ����
	int sizeH_;	// �c��
};
