#include "DoublyLinkedList.h"
#include "stdio.h"
#include "stdlib.h"

void DoubleList::Initialize()
{
	//先頭に内容が空のセルを宣言
	head.prev = nullptr;
	head.next = nullptr;
}

void DoubleList::DrawMessage()
{
	printf("1.要素の表示\n");
	printf("2.要素の挿入\n");
	printf("3.要素の編集\n");
	printf("4.要素の削除\n");
	printf("5.要素の並び替え(オプション)\n");
	printf("\n");
	printf("\n");
	printf("--------------------------------------\n");
	printf("操作の選択をしてください\n");

}

void DoubleList::Update()
{
	printf("何番目のセルの後ろに挿入しますか\n");
	scanf_s("%d", &iterator);

	printf("挿入する値を入力してください\n");
	scanf_s("%d", &inputValue);

	//任意のセルの後ろに追加
	insertCell = GetInsertCellAddress(&head,iterator);
	Create(insertCell, inputValue);

	Index(&head);
	//Index(&head);

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

//セルの一覧表示
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