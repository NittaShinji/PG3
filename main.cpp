#include "DoublyLinkedList.h"
#include "stdio.h"

int main()
{
	//�擪�̃Z���̐錾
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