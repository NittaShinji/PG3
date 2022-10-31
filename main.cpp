#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <functional>

int main(int argc, const char *argv[])
{
	//サイコロの値
	srand(time(nullptr));
	int diceNum = rand() % 6 + 1;
	//サイコロの乱数から値の判別(偶数か奇数か)
	int correct = diceNum % 2;
	
	//プレイヤー入力
	printf("偶数か奇数を入力してください\n");
	int playerNum = 0;
	scanf_s("%d", &playerNum);
	printf("抽選スタート\n");

	//待ち時間
	int waitTime = 3;
	
	//指定秒数待つ関数
	std::function<void()> setSleep = [=]() {Sleep(waitTime * 1000); };
	
	//結果を表示する関数
	std::function<void()> displayResult = [=]() {playerNum % 2 == correct ? printf("当たりです\n") : printf("外れです\n");};

	//コールバック関数(先生のお手本型)
	/*std::function<void(std::function<void()>, int)> setTimeOut = [](std::function<void()> fx, int second) {Sleep(second * 1000); fx();};
	setTimeOut(displayResult, 3);*/

	//待ってから実行する関数
	std::function<void()> setTimeOut = [=]() {setSleep(); displayResult(); };
	setTimeOut();

	return 0;
}