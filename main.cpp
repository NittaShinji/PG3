#include "stdio.h"
#include "stdlib.h"
#include <windows.h>
#include "time.h"
#include "SceneManager.h"


int main()
{
	//インスタンスの取得
	SceneManager* sceneManager = SceneManager::GetInstance();

	//シーン番号
	int sceneNo = 0;
	//待つ秒数
	const int second = 2;

	while (true)
	{
		//使用
		sceneManager->ChangeScene(sceneNo);
		//表示
		printf("%d\n", sceneManager->GetSceneNo());
		//ループ処理
		if(sceneNo < 4)
		{
			sceneNo++;
		}
		else
		{
			sceneNo = 0;
		}
		//2秒間待つ
		Sleep(second * 1000);
	}
	
	system("PAUSE");
	return 0;
}

	