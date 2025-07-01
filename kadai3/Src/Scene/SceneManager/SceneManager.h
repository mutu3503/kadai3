#pragma once

//�N���X�̑O���錾
class SceneBase;

class SceneManager
{
public:
	//�V�[���Ǘ��p
	enum class SCENE_ID
	{
		NONE,	//�Ȃ�
		TITLE,	//�^�C�g���V�[��
		GAME,	//�Q�[���V�[��
	};

public:
	//�V���O���g���i�����E�擾�E�폜�j
	static void CreateInstance(void)
	{
		if (instance_ == nullptr)
		{
			instance_ = new SceneManager();
		}
	};
	static SceneManager* GetInstance(void)
	{
		return instance_;
	};
	static void DeleteInstance(void)
	{
		if (instance_ != nullptr)
		{
			delete instance_;
			instance_ = nullptr;
		}
	}

private:
	//�R���X�g���N�^
	SceneManager(void);
	//�f�X�g���N�^
	~SceneManager(void);

	//�ÓI�C���X�^���X
	static SceneManager* instance_;

public:

	void Init(void);	//������
	void Init3D(void);	//�RD���̏�����
	void Update(void);	//�X�V
	void Draw(void);	//�`��
	void Release(void);	//���

	//��ԑJ��
	void ChangeScene(SCENE_ID nextId);

	//�V�[��ID�̎擾
	SCENE_ID DetSceneID(void) { return sceneId_; }

	//�Q�[���I��
	void GameEnd(void) { isGameEnd_ = true; }

	//�Q�[���I���t���O�̎擾
	bool GetGameEnd(void) { return isGameEnd_; }

private:
	//�e��V�[��
	SceneBase* scene_;

	//�V�[��ID
	SCENE_ID sceneId_;

	//�Q�[���I��
	bool isGameEnd_;
};