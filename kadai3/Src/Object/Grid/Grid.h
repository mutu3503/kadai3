#pragma once

class Grid
{
public:
	//定数定義

	//線の長さ
	static constexpr float LEN = 3000.0f;

	//線の長さの半分
	static constexpr float HLEN = LEN / 2.0f;

	//線の間隔
	static constexpr float DISTANCE = 100.0f;

	static constexpr int NUM = static_cast<int>(LEN / DISTANCE);

	static constexpr int HNUM = NUM / 2;

	Grid(void);

	~Grid(void);

	void Init(void);	//初期化
	void Load(void);	//読み込み
	void Update(void);	//更新
	void Draw(void);	//描画
	void Release(void);	//解放
};
