#pragma once
#include "stdio.h"

class IShape
{
public: //メンバ関数

	//コンストラクタ
	IShape() : x(6), y(6), r(3),area(0) {}
	virtual void Size() = 0;	//面積を求める
	virtual void Draw() = 0;	//面積を表示

protected:

	//各座標
	float x;
	float y;
	//半径
	float r;
	//面積
	float area;
};
