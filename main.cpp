#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <functional>

//���ʂ�\������֐�
void ShowDown(int correct, int playerNum)
{
	//����
	if (playerNum % 2 == correct)
	{
		printf("������ł�\n");
	}
	//�
	else if (playerNum % 2 != correct)
	{
		printf("�O��ł�\n");
		if (correct == 0)
		{
			printf("�_�C�X�͋���\n");
		}
		if (correct == 1)
		{
			printf("�_�C�X�͊\n");
		}
	}
	else {}
}

int main(int argc, const char *argv[])
{
	//�T�C�R���̒l
	srand(time(nullptr));
	int diceNum = rand() % 6 + 1;
	//�T�C�R���̗�������l�̔���(���������)
	int correct = diceNum % 2;
	
	//�v���C���[����
	printf("�����������͂��Ă�������\n");
	int playerNum = 0;
	scanf_s("%d", &playerNum);
	printf("���I�X�^�[�g\n");
	
	//3�b�҂�
	std::function<void(int)> setSleep = [](int second) {Sleep(second * 1000); };
	setSleep(3);

	//���ʂ�\��
	ShowDown(correct, playerNum);

	return 0;
}