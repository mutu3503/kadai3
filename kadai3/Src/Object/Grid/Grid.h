#pragma once

class Grid
{
public:
	//�萔��`

	//���̒���
	static constexpr float LEN = 3000.0f;

	//���̒����̔���
	static constexpr float HLEN = LEN / 2.0f;

	//���̊Ԋu
	static constexpr float DISTANCE = 100.0f;

	static constexpr int NUM = static_cast<int>(LEN / DISTANCE);

	static constexpr int HNUM = NUM / 2;

	Grid(void);

	~Grid(void);

	void Init(void);	//������
	void Load(void);	//�ǂݍ���
	void Update(void);	//�X�V
	void Draw(void);	//�`��
	void Release(void);	//���
};
