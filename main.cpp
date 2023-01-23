#include "stdio.h"
#include "stdlib.h"
#include <windows.h>
#include "time.h"
#include "Enemy.h"

int main()
{
	//敵のインスタンスを生成
	Enemy *enemy1 = new Enemy();
	
	while (true)
	{
		//敵の更新処理
		enemy1->Update();
	}
	
	//インスタンスの破棄
	delete enemy1;
	
	system("PAUSE");
	return 0;
}

	