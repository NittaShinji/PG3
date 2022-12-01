#include "DoublyLinkedList.h"
#include "stdio.h"
#include "stdlib.h"

void DoubleList::Initialize()
{
	//�擪�ɓ��e����̃Z����錾
	head.prev = nullptr;
	head.next = nullptr;
}

void DoubleList::DrawMessage()
{
	printf("1.�v�f�̕\��\n");
	printf("2.�v�f�̑}��\n");
	printf("3.�v�f�̕ҏW\n");
	printf("4.�v�f�̍폜\n");
	printf("5.�v�f�̕��ёւ�(�I�v�V����)\n");
	printf("\n");
	printf("\n");
	printf("--------------------------------------\n");
	printf("����̑I�������Ă�������\n");

}

void DoubleList::Update()
{
	printf("���Ԗڂ̃Z���̌��ɑ}�����܂���\n");
	scanf_s("%d", &iterator);

	printf("�}������l����͂��Ă�������\n");
	scanf_s("%d", &inputValue);

	//�C�ӂ̃Z���̌��ɒǉ�
	insertCell = GetInsertCellAddress(&head,iterator);
	Create(insertCell, inputValue);

	Index(&head);
	//Index(&head);

}

//�C�ӂ̈ʒu�̃A�h���X���擾
CELL* DoubleList::GetInsertCellAddress(CELL* endCELL, int iterator)
{
	for (int i = 0; i < iterator; i++)
	{
		if (endCELL->next) 
		{
			endCELL = endCELL->next;
		}
		else
		{
			//�C�e���[�^���傫�Ȑ��ɂȂ����甲����
			break;
		}
	}

	return endCELL;
}

//�l�̒ǉ�
void DoubleList::Create(CELL *currentCell, int inputValue)
{
	// �V�K�ɃZ�����쐬
	CELL* newCell;
	newCell = (CELL*)malloc(sizeof(CELL));
	newCell->value = inputValue;
	newCell->prev = currentCell;
	newCell->next = currentCell->next;

	// �w�肵���Z���̎��̃Z����
	//�u�O�̃Z���̃|�C���^�v�ɐV�K�Z���̃A�h���X����(1,2,3��3�̑O�Z��)
	if (currentCell->next)
	{
		CELL* nextCell = currentCell->next;
		nextCell->prev = newCell;
	}

	//�w�肵���Z���́u���̃Z���̃|�C���^�v�ɐV�K�Z���̃A�h���X����(1,2,3��2�̎��Z��)
	currentCell->next = newCell;

}

//�Z���̈ꗗ�\��
void DoubleList::Index(CELL* endCell)
{
	int no = 1;
	while (endCell->next != nullptr)
	{
		endCell = endCell->next;
		printf("%d\n", no);
		printf("%p\n", endCell->prev);
		printf("%5d\n", endCell->value);
		printf("(%p)\n", endCell);
		printf("%p\n", endCell->next);
		no++;
	}
}