#pragma once

//クラスの前方宣言
class SceneBase;

class SceneManager
{
public:
	//シーン管理用
	enum class SCENE_ID
	{
		NONE,	//なし
		TITLE,	//タイトルシーン
		GAME,	//ゲームシーン
	};

public:
	//シングルトン（生成・取得・削除）
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
	//コンストラクタ
	SceneManager(void);
	//デストラクタ
	~SceneManager(void);

	//静的インスタンス
	static SceneManager* instance_;

public:

	void Init(void);	//初期化
	void Init3D(void);	//３D情報の初期化
	void Update(void);	//更新
	void Draw(void);	//描画
	void Release(void);	//解放

	//状態遷移
	void ChangeScene(SCENE_ID nextId);

	//シーンIDの取得
	SCENE_ID DetSceneID(void) { return sceneId_; }

	//ゲーム終了
	void GameEnd(void) { isGameEnd_ = true; }

	//ゲーム終了フラグの取得
	bool GetGameEnd(void) { return isGameEnd_; }

private:
	//各種シーン
	SceneBase* scene_;

	//シーンID
	SCENE_ID sceneId_;

	//ゲーム終了
	bool isGameEnd_;
};