#pragma once
#include "stdio.h"

class IShape
{
public: //�����o�֐�

	//�R���X�g���N�^
	IShape() : x(6), y(6), r(3),area(0) {}
	virtual void Size() = 0;	//�ʐς����߂�
	virtual void Draw() = 0;	//�ʐς�\��

protected:

	//�e���W
	float x;
	float y;
	//���a
	float r;
	//�ʐ�
	float area;
};
