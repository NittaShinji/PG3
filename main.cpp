#include"stdio.h"

//�����̌v�Z
int Recursive(int n)
{
	if (n <= 1)
	{
		return(1);
	}

	return (n * Recursive(n - 1));
}

//��r
int Compare(int a,int b)
{
	if (a >= b)
	{
		return printf("%d�̕����ׂ����Ă���\n",a);
	}
	return printf("%d�̕����ׂ����Ă���\n", b);
}

int main()
{
	int n = 10;	//�K�悷��l
	int result; //�v�Z����
	//��ʓI�Ȓ���
	const int generalWage = 1072;

	result = Recursive(n);
	printf("%d�̊K�� = %d\n", n, result);
	Compare(generalWage, result);

}