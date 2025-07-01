#pragma once
#include"../SceneBase.h"

//ベースを継承
class GameScene : public SceneBase	
{
public:
	GameScene();						//コンストラクタ
	~GameScene()			override;	//デストラクタ

	void Init(void)			override;	//初期化
	void Load(void)			override;	//読み込み
	void LoadEnd(void)		override;	//読み込み後
	void Update(void)		override;	//更新
	void Draw(void)			override;	//描画
	void Release(void)		override;	//解放
};