#include "DoublyLinkedList.h"
#include "stdio.h"
#include "stdlib.h"

//初期化
template <typename T>
void DoubleList<T>::Initialize()
{
	scene = Scene::INITIAL;
	//先頭に内容が空のセルを宣言
	head.prev = nullptr;
	head.next = nullptr;
	isClose = false;
	displayNumber = 0;

	Create(&head, 6);
	Create(&head, 5);
	Create(&head, 4);
}

//全体の更新
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

//初期化更新
template <typename T>
void DoubleList<T>::InitialUpdate()
{
	sceneNumber = 0;
	printf("[要素の操作]\n");
	printf("1.要素の表示\n");
	printf("2.要素の挿入\n");
	if (sizeof(CELL<T>) != 0)
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

//表示更新
template <typename T>
void DoubleList<T>::DisplayUpdate()
{
	CELL<T>* displayCell;

	if (displayNumber == 0)
	{
		printf("[要素の表示]\n");
		printf("1.要素の一覧表示\n");
		printf("2.順番を指定して要素を表示\n");
		printf("9.要素操作に戻る\n");
		printf("\n");
		printf("操作の選択をしてください\n");
		while (displayNumber != 1 && displayNumber != 2 && displayNumber != 9)
		{
			scanf_s("%d", &displayNumber);
			scanf_s("%*[^\n]%*c");
		}
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

		printf("\n[順番を指定して要素を表示]\n");
		printf("表示したい要素の順番を指定してください。\n");

		printf("要素一覧:\n");
		printf("{\n\n");
		IndexNumber(&head);
		printf("}\n\n");

		scanf_s("%d", &number);
		scanf_s("%*[^\n]%*c");
		printf("\n");
		printf("--------------------------------------\n");

		displayCell = GetInsertCellAddress(&head, number);
		printf("%5d\n", displayCell->value);

		printf("1.要素の表示に戻る\n");
		printf("2.要素の操作に戻る\n");

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

//挿入
template <typename T>
void DoubleList<T>::InsertUpdate()
{
	CELL<T>* insertCell;
	//追加する場所の数
	int insertNum = 0;
	//追加する要素
	int value = 0;

	printf("[リスト要素の挿入]\n");
	printf("要素を追加する場所を指定してください。最後尾についかする場合は0を入力してください。\n");
	scanf_s("%d", &insertNum);
	scanf_s("%*[^\n]%*c");
	printf("\n");
	printf("追加する要素の値を入力してください。\n");
	scanf_s("%d", &value);
	scanf_s("%*[^\n]%*c");
	printf("\n");
	
	if (insertNum == 0)
	{
		int size = sizeof(head);

		insertCell = MoveEndCell(&head);
		Create(insertCell, value);
		printf("要素%dが最後に挿入されました。\n", value);
	}
	else if (insertNum != 0)
	{
		insertCell = GetInsertCellAddress(&head, insertNum);
		Create(insertCell, value);
		printf("要素%dが%d番目に挿入されました。\n", value, insertNum);
	}
	
	printf("\n");

	ReturnHome();
}

//編集
template <typename T>
void DoubleList<T>::EditUpdate()
{
	CELL<T>* changeCell;
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
		printf("%d番目の要素の変更後の値を入力してください。\n",editNumber);
		scanf_s("%d", &changeNumber);
		scanf_s("%*[^\n]%*c");
		printf("\n");
		printf("\n");
		changeCell = GetInsertCellAddress(&head, editNumber);
		changeCell->value = changeNumber;
		printf("%d番目の要素の値が%dに変更されました\n",editNumber,changeNumber);
	}
	
	else if (notFindNumber == true)
	{
		printf("%d番目の要素が見つかりませんでした。\n",editNumber);
		notFindNumber = false;
	}

	ReturnHome();
}

//削除
template <typename T>
void DoubleList<T>::DeleteUpdate()
{
	CELL<T>* deleteCell;
	int deleteNumber = 0;
	printf("[要素の削除]\n");
	printf("削除したい要素の番号を指定してください。\n");

	printf("要素一覧:\n");
	printf("{\n\n");
	Index(&head);
	printf("}\n\n");

	scanf_s("%d", &deleteNumber);
	scanf_s("%*[^\n]%*c");
	printf("\n");
	
	deleteCell = GetInsertCellAddress(&head, deleteNumber);
	if (notFindNumber == false)
	{
		printf("%d番目の要素%dを削除しました\n", deleteNumber,deleteCell->value);
		printf("表の順番が変わりました\n");

		Delete(deleteCell);
	}
	else if(notFindNumber == true)
	{
		printf("%d番目の要素が見つかりませんでした。\n",deleteNumber);
		notFindNumber = false;
	}

	ReturnHome();
}

//並び替え
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
	printf("[要素の並び替え]\n");
	printf("要素番号AとBを入れ替えます。\n");
	printf("並び替えたい要素Aの番号を指定してください。\n");

	printf("要素一覧:\n");
	printf("{\n\n");
	Index(&head);
	printf("}\n\n");

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

	ReturnHome();
}

//任意の位置のアドレスを取得
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
			//イテレータより大きな数になったら抜ける
			notFindNumber = true;
			break;
		}
	}

	return endCELL;
}

//値の追加
template <typename T>
void DoubleList<T>::Create(CELL<T> *currentCell, T inputValue)
{
	// 新規にセルを作成
	CELL<T>* newCell;
	newCell = (CELL<T>*)malloc(sizeof(CELL<T>));
	newCell->value = inputValue;
	newCell->prev = currentCell;
	newCell->next = currentCell->next;

	// 指定したセルの次のセルの
	//「前のセルのポインタ」に新規セルのアドレスを代入(1,2,3の3の前セル)
	if (currentCell->next)
	{
		CELL<T>* nextCell = currentCell->next;
		nextCell->prev = newCell;
	}

	//指定したセルの「次のセルのポインタ」に新規セルのアドレスを代入(1,2,3の2の次セル)
	currentCell->next = newCell;
}

//要素の削除
template <typename T>
void DoubleList<T>::Delete(CELL<T>* currentCell)
{
	// 指定したセルの次のセルの
	//「前のセルのポインタ」に指定したセルの前のアドレスを代入(1,2,3の3の前セル)
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

//セルの一覧表示
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

//セルの番号表示
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

//セルの最後まで表示
template <typename T>
CELL<T>* DoubleList<T>::MoveEndCell(CELL<T>* endCell)
{
	while (endCell->next != nullptr)
	{
		endCell = endCell->next;
	}
	
	return endCell;
}

//ホームに戻る
template <typename T>
void DoubleList<T>::ReturnHome()
{
	printf("9.要素操作に戻る\n");

	//9以外が押された場合は再度入力させる。
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
