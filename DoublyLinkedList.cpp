#include "DoublyLinkedList.h"
#include "stdio.h"
#include "stdlib.h"

void DoubleList::Initialize()
{
	scene = Scene::INITIAL;
	//�擪�ɓ��e����̃Z����錾
	head.prev = nullptr;
	head.next = nullptr;
	isClose = false;
	displayNumber = 0;
}

void DoubleList::Update()
{
	switch (scene)
	{
	case Scene::INITIAL:

		InitialUpdate();
		break;
		
	case Scene::DISPLAY:

		DisplayUpdate();
		break;

	case Scene::INSERT:

		InsertUpdate();
		break;

	case Scene::EDIT:

		break;

	case Scene::DELETE:
		break;

	case Scene::SORT:
		break;

	default:
		break;
	}

	//printf("���Ԗڂ̃Z���̌��ɑ}�����܂���\n");
	//scanf_s("%d", &iterator);

	//printf("�}������l����͂��Ă�������\n");
	//scanf_s("%d", &inputValue);

	////�C�ӂ̃Z���̌��ɒǉ�
	//insertCell = GetInsertCellAddress(&head,iterator);
	//Create(insertCell, inputValue);

	//Index(&head);
}


void DoubleList::InitialUpdate()
{
	sceneNumber = 0;
	printf("[�v�f�̑���]\n");
	printf("1.�v�f�̕\��\n");
	printf("2.�v�f�̑}��\n");
	if (sizeof(CELL) != 0)
	{
		printf("3.�v�f�̕ҏW\n");
		printf("4.�v�f�̍폜\n");
	}
	printf("5.�v�f�̕��ёւ�(�I�v�V����)\n");
	printf("6.�I������\n");
	printf("\n");
	printf("\n");
	printf("--------------------------------------\n");
	printf("����̑I�������Ă�������\n");
	scanf_s("%d", &sceneNumber);
	scanf_s("%*[^\n]%*c");

	if (sceneNumber == 1)
	{
		scene = Scene::DISPLAY;
	}
	else if (sceneNumber == 2)
	{
		scene = Scene::INSERT;
	}
	else if (sceneNumber == 3)
	{
		scene = Scene::EDIT;
	}
	else if (sceneNumber == 4)
	{
		scene = Scene::DELETE;
	}
	else if (sceneNumber == 5)
	{
		scene = Scene::SORT;
	}
	else if (sceneNumber == 6)
	{
		isClose = true;
	}
}


void DoubleList::DisplayUpdate()
{
	if (displayNumber == 0)
	{
		printf("[�v�f�̕\��]\n");
		printf("1.�v�f�̈ꗗ�\��\n");
		printf("2.���Ԃ��w�肵�ėv�f��\��\n");
		printf("9.�v�f����ɖ߂�\n");
		printf("\n");
		printf("����̑I�������Ă�������\n");
		scanf_s("%d", &displayNumber);
		scanf_s("%*[^\n]%*c");

	}
	else if (displayNumber == 1)
	{
		int number = 0;
		printf("\n[�v�f�̈ꗗ�\��]\n");
		printf("�v�f�ꗗ:{\n");

		Index(&head);
		printf("}\n\n");

		printf("--------------------------------------\n\n");
		printf("1.�v�f�̕\���ɖ߂�\n");
		printf("2.�v�f�̑���ɖ߂�\n");
		scanf_s("%d", &number);
		scanf_s("%*[^\n]%*c");
		if (number == 1)
		{
			number = 0;
			displayNumber = 0;
		}
		else if (number == 2)
		{
			number = 0;
			displayNumber = 0;
			scene = Scene::INITIAL;
		}

	}
	else if (displayNumber == 2)
	{
		int number = 0;
		
		printf("\n[���Ԃ��w�肵�ėv�f��\��]\n");
		printf("�\���������v�f�̏��Ԃ��w�肵�Ă��������B\n");
		scanf_s("%d", &number);
		scanf_s("%*[^\n]%*c");
		printf("\n");
		printf("--------------------------------------\n");

		displayCell = GetInsertCellAddress(&head, number);
		printf("%5d\n", displayCell->value);

		printf("1.�v�f�̕\���ɖ߂�\n");
		printf("2.�v�f�̑���ɖ߂�\n");

		scanf_s("%d", &returnNumber);
		scanf_s("%*[^\n]%*c");

		if (returnNumber == 1)
		{
			displayNumber = 0;
			returnNumber = 0;
		}
		else if (returnNumber == 2)
		{
			displayNumber = 0;
			scene = Scene::INITIAL;
			returnNumber = 0;
		}
	}
	else if (displayNumber == 9)
	{
		displayNumber = 0;
		scene = Scene::INITIAL;
	}
}

void DoubleList::InsertUpdate()
{
	//�ǉ�����ꏊ�̐�
	int insertNum = 0;
	//�ǉ�����v�f
	int value = 0;
	
	printf("[���X�g�v�f�̑}��]\n");
	printf("�v�f��ǉ�����ꏊ���w�肵�Ă��������B�Ō���ɂ�������ꍇ�͉������͂��Ȃ��ł��������B\n");
	scanf_s("%d", &insertNum);
	scanf_s("%*[^\n]%*c");
	printf("\n");
	printf("�ǉ�����v�f�̒l����͂��Ă��������B\n");
	scanf_s("%d", &value);
	scanf_s("%*[^\n]%*c");
	printf("\n");
	
	GetInsertCellAddress(&head, insertNum);
	Create(&head, value);

	printf("�v�f%d��%d�Ԗڂɑ}������܂����B\n",value,insertNum);
	printf("\n");

	ReturnHome();
}

void DoubleList::EditUpdate()
{
	CELL* changeCell;
	int editNumber = 0;
	int changeNumber = 0;
	printf("[�v�f�̕ҏW]\n");
	printf("�ҏW�������v�f�̔ԍ����w�肵�Ă��������B\n");
	scanf_s("%d", &editNumber);
	scanf_s("%*[^\n]%*c");
	GetInsertCellAddress(&head, editNumber);
	printf("\n");
	printf("\n");
	printf("\n");
	
	if (notFindNumber == false)
	{
		printf("%d�Ԗڂ̗v�f�̕ύX����l����͂��Ă��������B\n",editNumber);
		scanf_s("%d", &changeNumber);
		scanf_s("%*[^\n]%*c");
		printf("\n");
		printf("\n");
		changeCell = GetInsertCellAddress(&head, editNumber);
		changeCell->value = changeNumber;
	}
	//printf("x�Ԗڂ̗v�f�̒l��"xx"�ɕύX����܂���");
	else if (notFindNumber == true)
	{
		printf("x�Ԗڂ̗v�f��������܂���ł����B\n");
		notFindNumber = false;
	}
	//printf("��x�Ԗڂ��Ȃ��ꍇ\n");
	
	ReturnHome();
}


void DoubleList::DeleteUpdate()
{
	CELL* deleteCell;
	int deleteNumber = 0;
	printf("[�v�f�̍폜]\n");
	printf("�폜�������v�f�̔ԍ����w�肵�Ă��������B\n");
	scanf_s("%d", &deleteNumber);
	scanf_s("%*[^\n]%*c");
	printf("\n");
	
	deleteCell = GetInsertCellAddress(&head, deleteNumber);
	if (notFindNumber == false)
	{
		printf("%d�Ԗڂ̗v�f%d���폜���܂���\n", deleteNumber,deleteCell->value);
		Delete(deleteCell);
	}
	else if(notFindNumber == true)
	{
		printf("%d�Ԗڂ̗v�f��������܂���ł����B\n",deleteNumber);
		notFindNumber = false;
	}
}

void DoubleList::SortUpdate()
{

	CELL* changeA;
	CELL* changeB;

	int numberA = 0;
	int numberB = 0;
	int valueA = 0;
	int valueB = 0;
	bool isChange = true;
	printf("[�v�f�̕��ёւ�]\n");
	printf("�v�f�ԍ�A��B�����ւ��܂��B\n");
	printf("���ёւ������v�fA�̔ԍ����w�肵�Ă��������B\n");
	scanf_s("%d", &numberA);
	scanf_s("%*[^\n]%*c");
	changeA = GetInsertCellAddress(&head, numberA);
	if (notFindNumber == true)
	{
		printf("%d�Ԗڂ̗v�f��������܂���ł����B\n", numberA);
		notFindNumber = false;
		isChange = false;
	}

	printf("\n");
	printf("���ёւ������v�fB�̔ԍ����w�肵�Ă��������B\n");
	scanf_s("%d", &numberB);
	scanf_s("%*[^\n]%*c");
	changeB = GetInsertCellAddress(&head, numberB);
	if (notFindNumber == true)
	{
		printf("%d�Ԗڂ̗v�f��������܂���ł����B\n", numberB);
		notFindNumber = false;
		isChange = false;
	}

	printf("�v�f�ԍ�%d:%d��%d:%d�����ւ��܂����B\n", numberA,changeA->value,numberB,changeB->value);

	if (isChange == true)
	{
		valueA = changeA->value;
		valueB = changeB->value;
		changeA->value = valueB;
		changeB->value = valueA;
	}

	printf("\n");
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
			notFindNumber = true;
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

//�v�f�̍폜
void DoubleList::Delete(CELL* currentCell)
{
	// �w�肵���Z���̎��̃Z����
	//�u�O�̃Z���̃|�C���^�v�Ɏw�肵���Z���̑O�̃A�h���X����(1,2,3��3�̑O�Z��)
	if (currentCell->next)
	{
		CELL* oldCell = currentCell->prev;
		CELL* nextCell = currentCell->next;
		nextCell->prev = oldCell;
		oldCell->next = nextCell;
	}

	delete currentCell;
}

//�Z���̈ꗗ�\��
void DoubleList::Index(CELL* endCell)
{
	int no = 0;
	while (endCell->next != nullptr)
	{
		/*endCell = endCell->next;
		printf("%d\n", no);
		printf("%p\n", endCell->prev);
		printf("%5d\n", endCell->value);
		printf("(%p)\n", endCell);
		printf("%p\n", endCell->next);
		no++;*/

		endCell = endCell->next;
		printf("%d:%d,\n", no,endCell->value);
		no++;
	}

	printf("\n");
}

void DoubleList::ReturnHome()
{
	printf("9.�v�f����ɖ߂�\n");
	scanf_s("%d", &returnNumber);
	scanf_s("%*[^\n]%*c");
	if (returnNumber == 9)
	{
		displayNumber = 0;
		scene = Scene::INITIAL;
		returnNumber = 0;
	}
}