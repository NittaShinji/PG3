#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <functional>

//コールバック関数
void CallBack(int correct, int playerNum)
{
	//偶数
	if (playerNum % 2 == correct)
	{
		printf("当たりです\n");
	}
	//奇数
	else if (playerNum % 2 != correct)
	{
		printf("外れです\n");
		if (correct == 0)
		{
			printf("ダイスは偶数\n");
		}
		if (correct == 1)
		{
			printf("ダイスは奇数\n");
		}
	}
	else {}
}

int main(int argc, const char *argv[])
{
	//サイコロの値
	srand(time(nullptr));
	int diceNum = rand() % 6 + 1;

	//ラムダ式
	//乱数から値の判別(偶数か奇数か)
	auto correct = [=]{return diceNum % 2; };
	
	printf("偶数か奇数を入力してください\n");
	//プレイヤー入力
	int playerNum = 0;
	scanf_s("%d", &playerNum);

	printf("抽選スタート\n");
	//三秒待つ
	std::function<void(int)> setSleep = [](int second) {Sleep(second * 1000); };
	setSleep(3);
	//結果を表示
	CallBack(correct(), playerNum);

	return 0;
}