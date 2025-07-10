#include<DxLib.h>
#include"Grid.h"

Grid::Grid()
{
}

Grid::~Grid()
{
}

void Grid::Init(void)
{
}

void Grid::Load(void)
{
}

void Grid::Update(void)
{
}

void Grid::Draw(void)
{
	//XZ��{���i�O���b�h�j
	float num;
	VECTOR sPos;
	VECTOR ePos;

	for (int i = -HNUM; i < HNUM; i++)
	{
		num = static_cast<float>(i);

		//X���i�ԁj
		sPos = { -HLEN,0.0f,num * DISTANCE };
		ePos = { HLEN,0.0f,num * DISTANCE };
		DrawLine3D(sPos, ePos, 0xff0000);
		DrawSphere3D(ePos, 20.0f, 10, 0xff0000, 0xff0000, true);

		//Z���i�j
		sPos = { num * DISTANCE,0.0f,-HLEN };
		ePos = { num * DISTANCE,0.0f,HLEN };
		DrawLine3D(sPos, ePos, 0x0000ff);
		DrawSphere3D(ePos, 20.0f, 10, 0x0000ff, 0x0000ff, true);
	}

	//Y���i�΁j
	sPos = { 0.0f,-HLEN, 0.0f };
	ePos = { 0.0f,HLEN, 0.0f };
	DrawLine3D(sPos, ePos, 0x00ff00);
	DrawSphere3D(ePos, 20.0f, 10, 0x00ff00, 0x00ff00, true);
}

void Grid::Release(void)
{
}
