#include "stdio.h"
#include "stdlib.h"
#include <windows.h>
#include "time.h"
#include "Enemy.h"

int main()
{
	//�G�̃C���X�^���X�𐶐�
	Enemy *enemy1 = new Enemy();
	Enemy *enemy2 = new Enemy(*enemy1);
	Enemy *enemy3 = new Enemy(*enemy1);
	Enemy *enemy4 = new Enemy(*enemy1);

	//�G�������Ă��邩�t���O
	bool isAlivedEnmey = true;
	//�҂b��
	const int second = 2;

	while (isAlivedEnmey)
	{
		//�G1�̂Ƀ_���[�W��^����
		enemy1->DamageEnemy();

		//HP�\��
		printf("�G��HP : %d\n", enemy1->GetEnemyHp());
		printf("�G��HP : %d\n", enemy2->GetEnemyHp());
		printf("�G��HP : %d\n", enemy3->GetEnemyHp());
		printf("�G��HP : %d\n\n", enemy4->GetEnemyHp());

		//�����G������ł�����Q�[�����I������
		if(enemy1->GetEnemyHp() == 0)
		{
			isAlivedEnmey = false;
		}

		//2�b�ԑ҂�
		Sleep(second * 1000);
	}
	
	//�C���X�^���X�̔j��
	delete enemy1;
	delete enemy2;
	delete enemy3;
	delete enemy4;

	system("PAUSE");
	return 0;
}

	