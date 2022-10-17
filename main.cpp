#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <windows.h>
#include <time.h>

typedef void (*PFunc)(int *);

//�R�[���o�b�N�֐�
void CallBack1(int *s)
{
	printf("%d�b��Ɏ��s������\n", *s);
}

//���b��ɌĂяo���֐�
void SetTimeOut(PFunc p,int second)
{
	//�R�[���o�b�N�֐����Ăяo��
	Sleep(second);
}

//�������o�͂���֐�
void ShowCorrect(int correct)
{
	if (correct == 0)
	{
		printf("�_�C�X�͋���\n");
	}
	if (correct == 1)
	{
		printf("�_�C�X�͊\n");
	}
}

int main()
{
	//�v���C���[���͗p�̕ϐ�
	int playerNum = 0;
	scanf_s("%d",&playerNum);

	//�T�C�R���̒l
	srand(time(nullptr));
	int diceNum = rand() % 6 + 1;

	//�����̒l�̔���(���������)
	int correct = diceNum % 2;
	
	//�֐��|�C���^
	PFunc p;
	p = CallBack1;

	printf("���I�X�^�[�g\n");
	//�����͎�t��
	//����
	if (playerNum % 2 == correct)
	{
		SetTimeOut(p, 3000);
		printf("������ł�\n");
	}
	//�
	else if (playerNum % 2 != correct)
	{
		SetTimeOut(p, 3000);
		printf("�O��ł�\n");
		ShowCorrect(correct);
	}
	else {}

	return 0;
}