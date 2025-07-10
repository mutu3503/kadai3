#pragma once

class Grid
{
public:
	//’è”’è‹`

	//ü‚Ì’·‚³
	static constexpr float LEN = 3000.0f;

	//ü‚Ì’·‚³‚Ì”¼•ª
	static constexpr float HLEN = LEN / 2.0f;

	//ü‚ÌŠÔŠu
	static constexpr float DISTANCE = 100.0f;

	static constexpr int NUM = static_cast<int>(LEN / DISTANCE);

	static constexpr int HNUM = NUM / 2;

	Grid(void);

	~Grid(void);

	void Init(void);	//‰Šú‰»
	void Load(void);	//“Ç‚İ‚İ
	void Update(void);	//XV
	void Draw(void);	//•`‰æ
	void Release(void);	//‰ğ•ú
};
