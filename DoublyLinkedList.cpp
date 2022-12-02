#include "DoublyLinkedList.h"
#include "stdio.h"
#include "stdlib.h"

void DoubleList::Initialize()
{
	scene = Scene::INITIAL;
	//先頭に内容が空のセルを宣言
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

	//printf("何番目のセルの後ろに挿入しますか\n");
	//scanf_s("%d", &iterator);

	//printf("挿入する値を入力してください\n");
	//scanf_s("%d", &inputValue);

	////任意のセルの後ろに追加
	//insertCell = GetInsertCellAddress(&head,iterator);
	//Create(insertCell, inputValue);

	//Index(&head);
}


void DoubleList::InitialUpdate()
{
	sceneNumber = 0;
	printf("[要素の操作]\n");
	printf("1.要素の表示\n");
	printf("2.要素の挿入\n");
	if (sizeof(CELL) != 0)
	{
		printf("3.要素の編集\n");
		printf("4.要素の削除\n");
	}
	printf("5.要素の並び替え(オプション)\n");
	printf("6.終了する\n");
	printf("\n");
	printf("\n");
	printf("--------------------------------------\n");
	printf("操作の選択をしてください\n");
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
		printf("[要素の表示]\n");
		printf("1.要素の一覧表示\n");
		printf("2.順番を指定して要素を表示\n");
		printf("9.要素操作に戻る\n");
		printf("\n");
		printf("操作の選択をしてください\n");
		scanf_s("%d", &displayNumber);
		scanf_s("%*[^\n]%*c");

	}
	else if (displayNumber == 1)
	{
		int number = 0;
		printf("\n[要素の一覧表示]\n");
		printf("要素一覧:{\n");

		Index(&head);
		printf("}\n\n");

		printf("--------------------------------------\n\n");
		printf("1.要素の表示に戻る\n");
		printf("2.要素の操作に戻る\n");
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
		
		printf("\n[順番を指定して要素を表示]\n");
		printf("表示したい要素の順番を指定してください。\n");
		scanf_s("%d", &number);
		scanf_s("%*[^\n]%*c");
		printf("\n");
		printf("--------------------------------------\n");

		displayCell = GetInsertCellAddress(&head, number);
		printf("%5d\n", displayCell->value);

		printf("1.要素の表示に戻る\n");
		printf("2.要素の操作に戻る\n");

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
	//追加する場所の数
	int insertNum = 0;
	//追加する要素
	int value = 0;
	
	printf("[リスト要素の挿入]\n");
	printf("要素を追加する場所を指定してください。最後尾についかする場合は何も入力しないでください。\n");
	scanf_s("%d", &insertNum);
	scanf_s("%*[^\n]%*c");
	printf("\n");
	printf("追加する要素の値を入力してください。\n");
	scanf_s("%d", &value);
	scanf_s("%*[^\n]%*c");
	printf("\n");
	
	GetInsertCellAddress(&head, insertNum);
	Create(&head, value);

	printf("要素%dが%d番目に挿入されました。\n",value,insertNum);
	printf("\n");

	ReturnHome();
}

void DoubleList::EditUpdate()
{
	CELL* changeCell;
	int editNumber = 0;
	int changeNumber = 0;
	printf("[要素の編集]\n");
	printf("編集したい要素の番号を指定してください。\n");
	scanf_s("%d", &editNumber);
	scanf_s("%*[^\n]%*c");
	GetInsertCellAddress(&head, editNumber);
	printf("\n");
	printf("\n");
	printf("\n");
	
	if (notFindNumber == false)
	{
		printf("%d番目の要素の変更する値を入力してください。\n",editNumber);
		scanf_s("%d", &changeNumber);
		scanf_s("%*[^\n]%*c");
		printf("\n");
		printf("\n");
		changeCell = GetInsertCellAddress(&head, editNumber);
		changeCell->value = changeNumber;
	}
	//printf("x番目の要素の値が"xx"に変更されました");
	else if (notFindNumber == true)
	{
		printf("x番目の要素が見つかりませんでした。\n");
		notFindNumber = false;
	}
	//printf("※x番目がない場合\n");
	
	ReturnHome();
}


void DoubleList::DeleteUpdate()
{
	CELL* deleteCell;
	int deleteNumber = 0;
	printf("[要素の削除]\n");
	printf("削除したい要素の番号を指定してください。\n");
	scanf_s("%d", &deleteNumber);
	scanf_s("%*[^\n]%*c");
	printf("\n");
	
	deleteCell = GetInsertCellAddress(&head, deleteNumber);
	if (notFindNumber == false)
	{
		printf("%d番目の要素%dを削除しました\n", deleteNumber,deleteCell->value);
		Delete(deleteCell);
	}
	else if(notFindNumber == true)
	{
		printf("%d番目の要素が見つかりませんでした。\n",deleteNumber);
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
	printf("[要素の並び替え]\n");
	printf("要素番号AとBを入れ替えます。\n");
	printf("並び替えたい要素Aの番号を指定してください。\n");
	scanf_s("%d", &numberA);
	scanf_s("%*[^\n]%*c");
	changeA = GetInsertCellAddress(&head, numberA);
	if (notFindNumber == true)
	{
		printf("%d番目の要素が見つかりませんでした。\n", numberA);
		notFindNumber = false;
		isChange = false;
	}

	printf("\n");
	printf("並び替えたい要素Bの番号を指定してください。\n");
	scanf_s("%d", &numberB);
	scanf_s("%*[^\n]%*c");
	changeB = GetInsertCellAddress(&head, numberB);
	if (notFindNumber == true)
	{
		printf("%d番目の要素が見つかりませんでした。\n", numberB);
		notFindNumber = false;
		isChange = false;
	}

	printf("要素番号%d:%dと%d:%dを入れ替えました。\n", numberA,changeA->value,numberB,changeB->value);

	if (isChange == true)
	{
		valueA = changeA->value;
		valueB = changeB->value;
		changeA->value = valueB;
		changeB->value = valueA;
	}

	printf("\n");
}

//任意の位置のアドレスを取得
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
			//イテレータより大きな数になったら抜ける
			notFindNumber = true;
			break;
		}
	}

	return endCELL;
}

//値の追加
void DoubleList::Create(CELL *currentCell, int inputValue)
{
	// 新規にセルを作成
	CELL* newCell;
	newCell = (CELL*)malloc(sizeof(CELL));
	newCell->value = inputValue;
	newCell->prev = currentCell;
	newCell->next = currentCell->next;

	// 指定したセルの次のセルの
	//「前のセルのポインタ」に新規セルのアドレスを代入(1,2,3の3の前セル)
	if (currentCell->next)
	{
		CELL* nextCell = currentCell->next;
		nextCell->prev = newCell;
	}

	//指定したセルの「次のセルのポインタ」に新規セルのアドレスを代入(1,2,3の2の次セル)
	currentCell->next = newCell;
}

//要素の削除
void DoubleList::Delete(CELL* currentCell)
{
	// 指定したセルの次のセルの
	//「前のセルのポインタ」に指定したセルの前のアドレスを代入(1,2,3の3の前セル)
	if (currentCell->next)
	{
		CELL* oldCell = currentCell->prev;
		CELL* nextCell = currentCell->next;
		nextCell->prev = oldCell;
		oldCell->next = nextCell;
	}

	delete currentCell;
}

//セルの一覧表示
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
	printf("9.要素操作に戻る\n");
	scanf_s("%d", &returnNumber);
	scanf_s("%*[^\n]%*c");
	if (returnNumber == 9)
	{
		displayNumber = 0;
		scene = Scene::INITIAL;
		returnNumber = 0;
	}
}