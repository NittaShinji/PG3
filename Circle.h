#pragma once
#include "IShape.h"

class Circle : public IShape
{
public:

	using IShape::IShape;	//�R���X�g���N�^���p��
	void Size() override;	//�ʐς����߂�
	void Draw() override;	//�ʐς�\��

private:

	//�~����
	const float PI = 3.141592654f;
};