#pragma once
#include "IShape.h"

class RectAngle : public IShape
{
public:
	using IShape::IShape;	//コンストラクタを継承
	void Size() override;	//面積を求める
	void Draw() override;	//面積を表示
};

