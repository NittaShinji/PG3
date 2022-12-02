#include "DoublyLinkedList.h"
#include "stdio.h"
#include "stdlib.h"

//������
template <typename T>
void DoubleList<T>::Initialize()
{
	scene = Scene::INITIAL;
	//�擪�ɓ��e����̃Z����錾
	head.prev = nullptr;
	head.next = nullptr;
	isClose = false;
	displayNumber = 0;

	Create(&head, 6);
	Create(&head, 5);
	Create(&head, 4);
}

//�S�̂̍X�V
template <typename T>
void DoubleList<T>::Update()
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

		EditUpdate();

		break;

	case Scene::DELETE:

		DeleteUpdate();
		break;

	case Scene::SORT:

		SortUpdate();
		break;

	default:
		break;
	}
}

//�������X�V
template <typename T>
void DoubleList<T>::InitialUpdate()
{
	sceneNumber = 0;
	printf("[�v�f�̑���]\n");
	printf("1.�v�f�̕\��\n");
	printf("2.�v�f�̑}��\n");
	if (sizeof(CELL<T>) != 0)
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

//�\���X�V
template <typename T>
void DoubleList<T>::DisplayUpdate()
{
	CELL<T>* displayCell;

	if (displayNumber == 0)
	{
		printf("[�v�f�̕\��]\n");
		printf("1.�v�f�̈ꗗ�\��\n");
		printf("2.���Ԃ��w�肵�ėv�f��\��\n");
		printf("9.�v�f����ɖ߂�\n");
		printf("\n");
		printf("����̑I�������Ă�������\n");
		while (displayNumber != 1 && displayNumber != 2 && displayNumber != 9)
		{
			scanf_s("%d", &displayNumber);
			scanf_s("%*[^\n]%*c");
		}
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
		while (number != 1 && number != 2)
		{
			scanf_s("%d", &number);
			scanf_s("%*[^\n]%*c");
		}

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
		int listSize = 0;

		printf("\n[���Ԃ��w�肵�ėv�f��\��]\n");
		printf("�\���������v�f�̏��Ԃ��w�肵�Ă��������B\n");

		printf("�v�f�ꗗ:\n");
		printf("{\n\n");
		IndexNumber(&head);
		printf("}\n\n");

		scanf_s("%d", &number);
		scanf_s("%*[^\n]%*c");
		printf("\n");
		printf("--------------------------------------\n");

		displayCell = GetInsertCellAddress(&head, number);
		printf("%5d\n", displayCell->value);

		printf("1.�v�f�̕\���ɖ߂�\n");
		printf("2.�v�f�̑���ɖ߂�\n");

		while (returnNumber != 1 && returnNumber != 2)
		{
			scanf_s("%d", &returnNumber);
			scanf_s("%*[^\n]%*c");
		}

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

//�}��
template <typename T>
void DoubleList<T>::InsertUpdate()
{
	CELL<T>* insertCell;
	//�ǉ�����ꏊ�̐�
	int insertNum = 0;
	//�ǉ�����v�f
	int value = 0;

	printf("[���X�g�v�f�̑}��]\n");
	printf("�v�f��ǉ�����ꏊ���w�肵�Ă��������B�Ō���ɂ�������ꍇ��0����͂��Ă��������B\n");
	scanf_s("%d", &insertNum);
	scanf_s("%*[^\n]%*c");
	printf("\n");
	printf("�ǉ�����v�f�̒l����͂��Ă��������B\n");
	scanf_s("%d", &value);
	scanf_s("%*[^\n]%*c");
	printf("\n");
	
	if (insertNum == 0)
	{
		int size = sizeof(head);

		insertCell = MoveEndCell(&head);
		Create(insertCell, value);
		printf("�v�f%d���Ō�ɑ}������܂����B\n", value);
	}
	else if (insertNum != 0)
	{
		insertCell = GetInsertCellAddress(&head, insertNum);
		Create(insertCell, value);
		printf("�v�f%d��%d�Ԗڂɑ}������܂����B\n", value, insertNum);
	}
	
	printf("\n");

	ReturnHome();
}

//�ҏW
template <typename T>
void DoubleList<T>::EditUpdate()
{
	CELL<T>* changeCell;
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
		printf("%d�Ԗڂ̗v�f�̕ύX��̒l����͂��Ă��������B\n",editNumber);
		scanf_s("%d", &changeNumber);
		scanf_s("%*[^\n]%*c");
		printf("\n");
		printf("\n");
		changeCell = GetInsertCellAddress(&head, editNumber);
		changeCell->value = changeNumber;
		printf("%d�Ԗڂ̗v�f�̒l��%d�ɕύX����܂���\n",editNumber,changeNumber);
	}
	
	else if (notFindNumber == true)
	{
		printf("%d�Ԗڂ̗v�f��������܂���ł����B\n",editNumber);
		notFindNumber = false;
	}

	ReturnHome();
}

//�폜
template <typename T>
void DoubleList<T>::DeleteUpdate()
{
	CELL<T>* deleteCell;
	int deleteNumber = 0;
	printf("[�v�f�̍폜]\n");
	printf("�폜�������v�f�̔ԍ����w�肵�Ă��������B\n");

	printf("�v�f�ꗗ:\n");
	printf("{\n\n");
	Index(&head);
	printf("}\n\n");

	scanf_s("%d", &deleteNumber);
	scanf_s("%*[^\n]%*c");
	printf("\n");
	
	deleteCell = GetInsertCellAddress(&head, deleteNumber);
	if (notFindNumber == false)
	{
		printf("%d�Ԗڂ̗v�f%d���폜���܂���\n", deleteNumber,deleteCell->value);
		printf("�\�̏��Ԃ��ς��܂���\n");

		Delete(deleteCell);
	}
	else if(notFindNumber == true)
	{
		printf("%d�Ԗڂ̗v�f��������܂���ł����B\n",deleteNumber);
		notFindNumber = false;
	}

	ReturnHome();
}

//���ёւ�
template <typename T>
void DoubleList<T>::SortUpdate()
{
	CELL<T>* changeA;
	CELL<T>* changeB;

	int numberA = 0;
	int numberB = 0;
	int valueA = 0;
	int valueB = 0;
	bool isChange = true;
	printf("[�v�f�̕��ёւ�]\n");
	printf("�v�f�ԍ�A��B�����ւ��܂��B\n");
	printf("���ёւ������v�fA�̔ԍ����w�肵�Ă��������B\n");

	printf("�v�f�ꗗ:\n");
	printf("{\n\n");
	Index(&head);
	printf("}\n\n");

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

	ReturnHome();
}

//�C�ӂ̈ʒu�̃A�h���X���擾
template <typename T>
CELL<T>* DoubleList<T>::GetInsertCellAddress(CELL<T>* endCELL, int iterator)
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
template <typename T>
void DoubleList<T>::Create(CELL<T> *currentCell, T inputValue)
{
	// �V�K�ɃZ�����쐬
	CELL<T>* newCell;
	newCell = (CELL<T>*)malloc(sizeof(CELL<T>));
	newCell->value = inputValue;
	newCell->prev = currentCell;
	newCell->next = currentCell->next;

	// �w�肵���Z���̎��̃Z����
	//�u�O�̃Z���̃|�C���^�v�ɐV�K�Z���̃A�h���X����(1,2,3��3�̑O�Z��)
	if (currentCell->next)
	{
		CELL<T>* nextCell = currentCell->next;
		nextCell->prev = newCell;
	}

	//�w�肵���Z���́u���̃Z���̃|�C���^�v�ɐV�K�Z���̃A�h���X����(1,2,3��2�̎��Z��)
	currentCell->next = newCell;
}

//�v�f�̍폜
template <typename T>
void DoubleList<T>::Delete(CELL<T>* currentCell)
{
	// �w�肵���Z���̎��̃Z����
	//�u�O�̃Z���̃|�C���^�v�Ɏw�肵���Z���̑O�̃A�h���X����(1,2,3��3�̑O�Z��)
	if (currentCell->next)
	{
		CELL<T>* oldCell = currentCell->prev;
		CELL<T>* nextCell = currentCell->next;
		nextCell->prev = oldCell;
		oldCell->next = nextCell;
		currentCell->prev = nullptr;
		currentCell->next = nullptr;
	}
	else if(currentCell->prev)
	{
		CELL<T>* oldCell = currentCell->prev;
		CELL<T>* nextCell = currentCell->next;
		oldCell->next = nullptr;
		nextCell->prev = nullptr;
		nextCell->next = nullptr;
	}
	else{}

	delete currentCell;
	currentCell = nullptr;
}

//�Z���̈ꗗ�\��
template <typename T>
void DoubleList<T>::Index(CELL<T>* endCell)
{
	int no = 1;
	while (endCell->next != nullptr)
	{
		endCell = endCell->next;
		printf("%d:%d,\n", no,endCell->value);
		no++;
	}

	printf("\n");
}

//�Z���̔ԍ��\��
template <typename T>
void DoubleList<T>::IndexNumber(CELL<T>* endCell)
{
	int no = 1;
	while (endCell->next != nullptr)
	{
		endCell = endCell->next;
		printf("%d:\n", no);
		no++;
	}

	printf("\n");
}

//�Z���̍Ō�܂ŕ\��
template <typename T>
CELL<T>* DoubleList<T>::MoveEndCell(CELL<T>* endCell)
{
	while (endCell->next != nullptr)
	{
		endCell = endCell->next;
	}
	
	return endCell;
}

//�z�[���ɖ߂�
template <typename T>
void DoubleList<T>::ReturnHome()
{
	printf("9.�v�f����ɖ߂�\n");

	//9�ȊO�������ꂽ�ꍇ�͍ēx���͂�����B
	while (returnNumber != 9)
	{
		scanf_s("%d", &returnNumber);
		scanf_s("%*[^\n]%*c");
	}

	if (returnNumber == 9)
	{
		displayNumber = 0;
		scene = Scene::INITIAL;
		returnNumber = 0;
	}
}

template class DoubleList<int>;
template class DoubleList<float>;
template class DoubleList<double>;

template class CELL<int>;
template class CELL<float>;
template class CELL<double>;
