#include "stdio.h"
#include "stdlib.h"
#include "string.h"

//�P�������X�g�̍\���̂��`
typedef struct Cell
{
	char name[16];
	int lendDate;
	int returnDate;
	struct Cell* next;
}; 

//�f�[�^��ǉ�����֐�
void Create(Cell* head, const char* buf);
//�ꗗ��\������֐�
void Index(Cell *head);

int main()
{
	char str[8];
	//�擪�̃Z���̐錾
	Cell head;
	head.next = nullptr;

	while (true)
	{
		scanf_s("%s",str,16);

		//�Ō���ɃZ����ǉ�
		Create(&head,str);

		//���X�g�ꗗ�̕\��
		Index(&head);
		break;
	}

	return 0;
}

void Create(Cell* head, const char *buf)
{
	Cell* newCell;

	newCell = (Cell*)malloc(sizeof(Cell));

	strcpy_s(newCell->name, 16, buf);

	newCell->next = nullptr;

	while (head->next != nullptr)
	{
		head = head->next;
	}

	head = newCell;

}

void Index(Cell* head)
{
	while (head->next != nullptr)
	{
		head = head->next;
		printf("%s\n", head->name);
	}
}