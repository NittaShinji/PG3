#include "DoublyLinkedList.h"
#include "stdio.h"

int main()
{
	//先頭のセルの宣言
	DoubleList* doubleList = nullptr;
	doubleList = new DoubleList;
	doubleList->Initialize();
	
	while (1)
	{
		doubleList->Update();
	}

	/*doubleList->Update();*/
	delete doubleList;

	return 0;
}