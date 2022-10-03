#include"stdio.h"

//賃金の計算
int Recursive(int n)
{
	if (n <= 1)
	{
		return(1);
	}

	return (n * Recursive(n - 1));
}

//比較
int Compare(int a,int b)
{
	if (a >= b)
	{
		return printf("%dの方が儲かっている\n",a);
	}
	return printf("%dの方が儲かっている\n", b);
}

int main()
{
	int n = 10;	//階乗する値
	int result; //計算結果
	//一般的な賃金
	const int generalWage = 1072;

	result = Recursive(n);
	printf("%dの階乗 = %d\n", n, result);
	Compare(generalWage, result);

}