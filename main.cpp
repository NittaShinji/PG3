#include"stdio.h"

//�ċA�I�����̌v�Z
int RecursiveResult(int t,int houlyWage)
{
	if (t <= 0)
	{
		return 0;
	}
	
	return  RecursiveResult(t - 1, houlyWage * 2 - 50) + houlyWage;
}

//��ʓI�Ȓ����̌v�Z
int GeneralResult(int t, int houlyWage)
{
	return t * houlyWage;
}

//�����̔�r
int Compare(int generalWage,int recursiveWage)
{
	if (generalWage >= recursiveWage)
	{
		return printf("��ʓI�Ȓ����̕����ׂ����Ă���\n");
	}
	
	return printf("�ċA�I�Ȓ����̕����ׂ����Ă���\n");
}

int main()
{
	int t = 8;					//����
	int generalWage = 1072;		//��ʓI�Ȓ���
	int recursiveWage = 100;	//�ċA�I�Ȓ���

	//�e�����̒l
	printf("��ʓI�Ȓ���%d\n", GeneralResult(t, generalWage));
	printf("�ċA�I�Ȓ���%d\n", RecursiveResult(t, recursiveWage));
	//�����̔�r
	Compare(GeneralResult(t, generalWage), RecursiveResult(t, recursiveWage));

	return 0;
}