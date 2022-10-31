#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

typedef void (*PFunc)(int*, int*);

//�R�[���o�b�N�֐�
void Lottery(int* correct, int* playerNum)
{
	//����
	if (*playerNum % 2 == *correct)
	{
		printf("������ł�\n");
	}
	//�
	else if (*playerNum % 2 != *correct)
	{
		printf("�O��ł�\n");
		if (*correct == 0)
		{
			printf("�_�C�X�͋���\n");
		}
		if (*correct == 1)
		{
			printf("�_�C�X�͊\n");
		}
	}
	else {}
}

void SetTimeOut(PFunc p, int second, int correct, int playerNum)
{
	//���b�ԑ҂�
	Sleep(second * 1000);
	//�R�[���o�b�N�֐����Ăяo��
	p(&correct, &playerNum);
}

int main()
{
	//�֐��|�C���^
	PFunc p;
	p = Lottery;

	//�T�C�R���̒l
	srand(time(nullptr));
	int diceNum = rand() % 6 + 1;
	//�T�C�R���̗�������l�̔���(���������)
	int correct = diceNum % 2;

	printf("�����������͂��Ă�������\n");
	//�v���C���[����
	int playerNum = 0;
	scanf_s("%d", &playerNum);
	printf("���I�X�^�[�g\n");
	
	//�O�b�҂��Č��ʂ�\��
	SetTimeOut(p, 3, correct, playerNum);

	return 0;
}