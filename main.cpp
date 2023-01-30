#include "stdio.h"
#include "Circle.h"
#include "RectAngle.h"
#include <windows.h>

int main()
{
	IShape *iShape[2];
	//インスタンスの生成
	for(int i = 0; i < 2; i++)
	{
		if(i < 1)
		{
			iShape[i] = new RectAngle;
		}
		else
		{
			iShape[i] = new Circle;
		}
	}

	//更新
	for(int i = 0; i < 2; i++)
	{
		iShape[i]->Size();
		iShape[i]->Draw();
	}

	//破棄
	for(int i = 0; i < 2; i++)
	{
		delete iShape[i];
	}

	system("PAUSE");
	return 0;
}