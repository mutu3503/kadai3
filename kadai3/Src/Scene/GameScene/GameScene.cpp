#include "GameScene.h"
#include<DxLib.h>
#include"../../Camera/Camera.h"
#include"../../Object/Grid/Grid.h"
#include"../../Object/Stage/Stage.h"
#include"../../Object/Player/Player.h"
GameScene::GameScene()
{
}

GameScene::~GameScene()
{
}

void GameScene::Init(void)
{
	//グリッドの初期化
	grid_->Init();

	//カメラの初期化
	Camera::GetInstance()->Init();

	//ステージの初期化
	stage_->Init();

	//プレイヤーの初期化
	player_->Init();
}

void GameScene::Load(void)
{
	//グリッドの生成
	grid_ = new Grid();

	//カメラの生成
	Camera::CreateInstance();
	
	//ステージの生成
	stage_ = new Stage();
	stage_->Load();

	//プレイヤーの生成
	player_ = new Player();
	player_->Load();
}

void GameScene::LoadEnd(void)
{
	//初期化
	Init();

	//ステージの読み込み後
	stage_->LoadEnd();
}

void GameScene::Update(void)
{
	//グリッドの更新
	grid_->Update();

	//カメラの更新
	Camera::GetInstance()->Update();

	//ステージの更新
	stage_->Update();

	//
	player_->Update();
}

void GameScene::Draw(void)
{
	//グリッドの描画
	grid_->Draw();

	//カメラの描画
	Camera::GetInstance()->SetBeforeDraw();
	Camera::GetInstance()->DebugDraw();

	//ステージの描画
	stage_->Draw();

	//プレイヤーの描画
	player_->Draw();
}

void GameScene::Release(void)
{
	//グリッドの解放
	grid_->Release();
	delete grid_;

	//カメラの解放
	Camera::GetInstance()->Release();
	Camera::DeleteInstance();

	//ステージの解放
	stage_->Release();
	delete stage_;

	//プレイヤーの解放
	player_->Release();
	delete player_;
}
