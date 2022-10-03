#include"stdio.h"

//関数テンプレート
template<typename Type>
Type Min(Type a, Type b)
{
	if (a >= b)
	{
		return static_cast<Type>(b);
	}
	return static_cast<Type>(a);
}

//テンプレートの特殊化(オーバーライド)
template<>
char Min<char>(char a, char b)
{
	return printf("数字以外は代入できません");
}

int main()
{
	printf("%d\n", Min<int>(114, 514));
	printf("%f\n", Min<float>(114, 514));
	printf("%lf\n",Min<double>(114, 514));
	printf("%c\n", Min<char>(114, 514));
}