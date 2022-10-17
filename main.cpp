#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <windows.h>
#include <time.h>

typedef void (*PFunc)(int *);

//コールバック関数
void CallBack1(int *s)
{
	printf("%d秒後に実行されるよ\n", *s);
}

//何秒後に呼び出す関数
void SetTimeOut(PFunc p,int second)
{
	//コールバック関数を呼び出す
	Sleep(second);
}

//正解を出力する関数
void ShowCorrect(int correct)
{
	if (correct == 0)
	{
		printf("ダイスは偶数\n");
	}
	if (correct == 1)
	{
		printf("ダイスは奇数\n");
	}
}

int main()
{
	//プレイヤー入力用の変数
	int playerNum = 0;
	scanf_s("%d",&playerNum);

	//サイコロの値
	srand(time(nullptr));
	int diceNum = rand() % 6 + 1;

	//正解の値の判別(偶数か奇数か)
	int correct = diceNum % 2;
	
	//関数ポインタ
	PFunc p;
	p = CallBack1;

	printf("抽選スタート\n");
	//＜入力受付＞
	//偶数
	if (playerNum % 2 == correct)
	{
		SetTimeOut(p, 3000);
		printf("当たりです\n");
	}
	//奇数
	else if (playerNum % 2 != correct)
	{
		SetTimeOut(p, 3000);
		printf("外れです\n");
		ShowCorrect(correct);
	}
	else {}

	return 0;
}