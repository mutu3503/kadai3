#include "SceneManager.h"

#include<DxLib.h>
#include"../TitleScene/TitleScene.h"
#include"../GameScene/GameScene.h"

SceneManager* SceneManager::instance_ = nullptr;

SceneManager::SceneManager(void) {}
SceneManager::~SceneManager(void) {}

void SceneManager::Init(void)
{
	Init3D();

	//最初はタイトルシーンから
	ChangeScene(SCENE_ID::TITLE);
}

void SceneManager::Init3D(void)
{
	//背景色設定
	SetBackgroundColor(0, 0, 0);

	//Zバッファを有効にする
	SetUseZBuffer3D(true);

	//Zバッファへの書き込みを有効にする
	SetWriteZBuffer3D(true);

	//バックカリングを有効にする
	SetUseBackCulling(true);

	//ライトの設定
	SetUseLighting(true);

	//正面から斜め下に向かったライト
	ChangeLightTypeDir({ 0.0f,-1.0f,1.0f });
}

void SceneManager::Update(void)
{
	//現在のシーンを更新
	scene_->Update();
}

void SceneManager::Draw(void)
{
	//現在のシーンを描画
	scene_->Draw();
}

void SceneManager::Release(void)
{
	//現在のシーンを解放・削除
	scene_->Release();
	delete scene_;
}

void SceneManager::ChangeScene(SCENE_ID nextId)
{
	//シーンを変更する
	sceneId_ = nextId;

	//現在のシーンを解放
	if (scene_ != nullptr)
	{
		scene_->Release();	//現在のシーンを解放
		delete scene_;		//シーンの削除
	}

	//各シーンに切り替え
	switch (sceneId_)
	{
	case SceneManager::SCENE_ID::NONE:
		break;
	case SceneManager::SCENE_ID::TITLE:
		scene_ = new TitleScene();
		break;
	case SceneManager::SCENE_ID::GAME:
		scene_ = new GameScene();
		break;
	default:
		break;
	}

	//初期化
	scene_->Init();
	scene_->Load();
}
