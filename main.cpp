#include"stdio.h"

//再帰的賃金の計算
int RecursiveResult(int t,int houlyWage)
{
	if (t <= 0)
	{
		return 0;
	}
	
	return  RecursiveResult(t - 1, houlyWage * 2 - 50) + houlyWage;
}

//一般的な賃金の計算
int GeneralResult(int t, int houlyWage)
{
	return t * houlyWage;
}

//賃金の比較
int Compare(int generalWage,int recursiveWage)
{
	if (generalWage >= recursiveWage)
	{
		return printf("一般的な賃金の方が儲かっている\n");
	}
	
	return printf("再帰的な賃金の方が儲かっている\n");
}

int main()
{
	int t = 8;					//時間
	int generalWage = 1072;		//一般的な賃金
	int recursiveWage = 100;	//再帰的な賃金

	//各賃金の値
	printf("一般的な賃金%d\n", GeneralResult(t, generalWage));
	printf("再帰的な賃金%d\n", RecursiveResult(t, recursiveWage));
	//賃金の比較
	Compare(GeneralResult(t, generalWage), RecursiveResult(t, recursiveWage));

	return 0;
}