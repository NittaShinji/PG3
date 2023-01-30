#pragma once
#include "IShape.h"

class Circle : public IShape
{
public:

	using IShape::IShape;	//コンストラクタを継承
	void Size() override;	//面積を求める
	void Draw();			//面積を表示

private:

	//円周率
	const float PI = 3.141592654f;
};