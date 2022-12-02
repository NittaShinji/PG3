#include "DoublyLinkedList.h"
#include "stdio.h"

int main()
{
	//先頭のセルの宣言
	DoubleList<int>* doubleList = nullptr;
	doubleList = new DoubleList<int>;
	doubleList->Initialize();
	
	while (1)
	{
		doubleList->Update();
		if (doubleList->GetisClose())
		{
			break;
		}
	}

	delete doubleList;

	return 0;
}