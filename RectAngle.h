#pragma once
#include "IShape.h"

class RectAngle : public IShape
{
public:
	using IShape::IShape;	//�R���X�g���N�^���p��
	void Size() override;	//�ʐς����߂�
	void Draw() override;	//�ʐς�\��
};

