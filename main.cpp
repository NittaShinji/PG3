#include "DoublyLinkedList.h"
#include "stdio.h"

int main()
{
	//æ“ª‚ÌƒZƒ‹‚ÌéŒ¾
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