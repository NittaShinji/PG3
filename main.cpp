#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

typedef void (*PFunc)(int*, int*);

//コールバック関数
void Lottery(int* correct, int* playerNum)
{
	//偶数
	if (*playerNum % 2 == *correct)
	{
		printf("当たりです\n");
	}
	//奇数
	else if (*playerNum % 2 != *correct)
	{
		printf("外れです\n");
		if (*correct == 0)
		{
			printf("ダイスは偶数\n");
		}
		if (*correct == 1)
		{
			printf("ダイスは奇数\n");
		}
	}
	else {}
}

void SetTimeOut(PFunc p, int second, int correct, int playerNum)
{
	//何秒間待つ
	Sleep(second * 1000);
	//コールバック関数を呼び出す
	p(&correct, &playerNum);
}

int main()
{
	//関数ポインタ
	PFunc p;
	p = Lottery;

	//サイコロの値
	srand(time(nullptr));
	int diceNum = rand() % 6 + 1;
	//サイコロの乱数から値の判別(偶数か奇数か)
	int correct = diceNum % 2;

	printf("偶数か奇数を入力してください\n");
	//プレイヤー入力
	int playerNum = 0;
	scanf_s("%d", &playerNum);
	printf("抽選スタート\n");
	
	//三秒待って結果を表示
	SetTimeOut(p, 3, correct, playerNum);

	return 0;
}