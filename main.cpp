#include "stdio.h"
#include "stdlib.h"
#include "string.h"

//単方向リストの構造体を定義
typedef struct Cell
{
	char name[16];
	int lendDate;
	int returnDate;
	struct Cell* next;
}; 

//データを追加する関数
void Create(Cell* head, const char* buf);
//一覧を表示する関数
void Index(Cell *head);

int main()
{
	char str[8];
	//先頭のセルの宣言
	Cell head;
	head.next = nullptr;

	while (true)
	{
		scanf_s("%s",str,16);

		//最後尾にセルを追加
		Create(&head,str);

		//リスト一覧の表示
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