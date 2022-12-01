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

#include "SceneManager.h"

int main()
{
	//インスタンスの取得
	SceneManager* sceneManager = SceneManager::GetInstance();

	int sceneNo = 0;
	int changeCount = 0;

	while (changeCount < 100)
	{
		changeCount = sceneManager->GetChangeCount();
		//使用
		sceneManager->ChangeScene(sceneNo);

		printf("%d\n", changeCount);
		printf("%d\n", sceneNo);

	}
	
	system("PAUSE");
	return 0;
}
