#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <functional>

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

	//�҂�����
	int waitTime = 3;
	
	//�w��b���҂֐�
	std::function<void()> setSleep = [=]() {Sleep(waitTime * 1000); };
	
	//���ʂ�\������֐�
	std::function<void()> displayResult = [=]() {playerNum % 2 == correct ? printf("������ł�\n") : printf("�O��ł�\n");};

	//�R�[���o�b�N�֐�(�搶�̂���{�^)
	/*std::function<void(std::function<void()>, int)> setTimeOut = [](std::function<void()> fx, int second) {Sleep(second * 1000); fx();};
	setTimeOut(displayResult, 3);*/

	//�҂��Ă�����s����֐�
	std::function<void()> setTimeOut = [=]() {setSleep(); displayResult(); };
	setTimeOut();

	return 0;
}