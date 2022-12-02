#include "DoublyLinkedList.h"
#include "stdio.h"

int main()
{
	//æ“ª‚ÌƒZƒ‹‚ÌéŒ¾
	DoubleList* doubleList = nullptr;
	doubleList = new DoubleList;
	doubleList->Initialize();
	
	while (1)
	{
		doubleList->Update();
		if (doubleList->GetisClose())
		{
			break;
		}
	}

	/*doubleList->Update();*/
	delete doubleList;

	return 0;
}