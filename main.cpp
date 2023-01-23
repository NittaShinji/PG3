#include "stdio.h"
#include "stdlib.h"
#include <windows.h>
#include "time.h"
#include "Enemy.h"

int main()
{
	//“G‚ÌƒCƒ“ƒXƒ^ƒ“ƒX‚ğ¶¬
	Enemy *enemy1 = new Enemy();
	Enemy *enemy2 = new Enemy(*enemy1);
	Enemy *enemy3 = new Enemy(*enemy1);
	Enemy *enemy4 = new Enemy(*enemy1);

	//“G‚ª¶‚«‚Ä‚¢‚é‚©ƒtƒ‰ƒO
	bool isAlivedEnmey = true;
	//‘Ò‚Â•b”
	const int second = 2;

	while (isAlivedEnmey)
	{
		//“G1‘Ì‚Éƒ_ƒ[ƒW‚ğ—^‚¦‚é
		enemy1->DamageEnemy();

		//HP•\¦
		printf("“G‚ÌHP : %d\n", enemy1->GetEnemyHp());
		printf("“G‚ÌHP : %d\n", enemy2->GetEnemyHp());
		printf("“G‚ÌHP : %d\n", enemy3->GetEnemyHp());
		printf("“G‚ÌHP : %d\n\n", enemy4->GetEnemyHp());

		//‚à‚µ“G‚ª€‚ñ‚Å‚¢‚½‚çƒQ[ƒ€‚ğI—¹‚·‚é
		if(enemy1->GetEnemyHp() == 0)
		{
			isAlivedEnmey = false;
		}

		//2•bŠÔ‘Ò‚Â
		Sleep(second * 1000);
	}
	
	//ƒCƒ“ƒXƒ^ƒ“ƒX‚Ì”jŠü
	delete enemy1;
	delete enemy2;
	delete enemy3;
	delete enemy4;

	system("PAUSE");
	return 0;
}

	