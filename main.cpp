#include"stdio.h"

//�֐��e���v���[�g
template<typename Type>
Type Min(Type a, Type b)
{
	if (a >= b)
	{
		return static_cast<Type>(b);
	}
	return static_cast<Type>(a);
}

//�e���v���[�g�̓��ꉻ(�I�[�o�[���C�h)
template<>
char Min<char>(char a, char b)
{
	return printf("�����ȊO�͑���ł��܂���");
}

int main()
{
	printf("%d\n", Min<int>(114, 514));
	printf("%f\n", Min<float>(114, 514));
	printf("%lf\n",Min<double>(114, 514));
	printf("%c\n", Min<char>(114, 514));
}