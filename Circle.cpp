#include "Circle.h"

//�ʐς����߂�
void Circle::Size()
{
	area =  r * r * PI;
}

//�ʐς�\��
void Circle::Draw()
{
	printf("�ʐ� : %f \n", area);
}
