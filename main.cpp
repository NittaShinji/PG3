#include "stdio.h"
#include "stdlib.h"
#include <windows.h>
#include "time.h"
#include "Enemy.h"

int main()
{
	//�G�̃C���X�^���X�𐶐�
	Enemy *enemy1 = new Enemy();
	
	while (true)
	{
		//�G�̍X�V����
		enemy1->Update();
	}
	
	//�C���X�^���X�̔j��
	delete enemy1;
	
	system("PAUSE");
	return 0;
}

	