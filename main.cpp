#include "stdio.h"
#include "stdlib.h"
#include <windows.h>
#include "time.h"
#include "Enemy.h"

int main()
{
	//敵のインスタンスを生成
	Enemy *enemy1 = new Enemy();
	Enemy *enemy2 = new Enemy(*enemy1);
	Enemy *enemy3 = new Enemy(*enemy1);
	Enemy *enemy4 = new Enemy(*enemy1);

	//敵が生きているかフラグ
	bool isAlivedEnmey = true;
	//待つ秒数
	const int second = 2;

	while (isAlivedEnmey)
	{
		//敵1体にダメージを与える
		enemy1->DamageEnemy();

		//HP表示
		printf("%d\n", enemy1->GetEnemyHp());
		printf("%d\n", enemy2->GetEnemyHp());
		printf("%d\n", enemy3->GetEnemyHp());
		printf("%d\n\n", enemy4->GetEnemyHp());

		//もし敵が死んでいたらゲームを終了する
		if(enemy1->GetEnemyHp() == 0)
		{
			isAlivedEnmey = false;
		}

		//2秒間待つ
		Sleep(second * 1000);
	}
	
	//インスタンスの破棄
	delete enemy1;
	delete enemy2;
	delete enemy3;
	delete enemy4;

	system("PAUSE");
	return 0;
}

	