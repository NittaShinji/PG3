#include "System.h"
#include <iostream>
#include <iomanip>

void System::Initialize()
{
	scene = Scene::INITIAL;
	isClose = false;
	isAddedTask = true;
	taskNum = 0;
}

void System::InitialUpdate()
{
	sceneNumber = 0;
	printf("\n");
	printf("[タスクの操作]\n");
	printf("1.タスクの表示\n");
	printf("2.タスクの新規作成\n");

	printf("3.タスクの編集\n");
	printf("4.タスクの削除\n");

	printf("5.終了する\n");
	printf("\n");
	printf("\n");
	printf("--------------------------------------\n");

	printf("操作の選択をしてください\n");
	scanf_s("%d", &sceneNumber);
	scanf_s("%*[^\n]%*c");
	if(sceneNumber == 1)
	{
		scene = Scene::DISPLAY;
	}
	else if(sceneNumber == 2)
	{
		scene = Scene::INSERT;
	}
	else if(sceneNumber == 3)
	{
		scene = Scene::EDIT;
	}
	else if(sceneNumber == 4)
	{
		//scene = Scene::DELETE;
	}
	else if(sceneNumber == 5)
	{
		isClose = true;
	}
}

void System::Update()
{
	//終了したタスクを削除(要らないタスクを削除できる機能が欲しいかも)
	/*tasks_.remove_if([](std::unique_ptr<Task>& task)
		{
			return task->GetStatus();
		});*/

		//タスク更新
	for(std::unique_ptr<Task>& task : tasks_)
	{
		task->Update();
	}

	switch(scene)
	{
	case Scene::INITIAL:

		InitialUpdate();
		break;

	case Scene::DISPLAY:

		DisplayUpdate();
		break;

	case Scene::INSERT:

		InsertUpdate();
		break;

	case Scene::EDIT:

		EditUpdate();

		break;

		/*case Scene::DELETE:

			DeleteUpdate();
			break;*/

	case Scene::SORT:

		//SortUpdate();
		break;

	default:
		break;
	}
}

void System::DisplayUpdate()
{
	if(displayNumber == 0)
	{
		printf("[タスクの表示]\n");
		printf("1.タスクの一覧表示\n");
		printf("2.順番を指定してタスクを表示\n");
		printf("9.タスク操作に戻る\n");
		printf("\n");
		printf("操作の選択をしてください\n");
		while(displayNumber != 1 && displayNumber != 2 && displayNumber != 9)
		{
			scanf_s("%d", &displayNumber);
			scanf_s("%*[^\n]%*c");
		}
	}
	else if(displayNumber == 1)
	{
		int number = 0;
		printf("\n[タスクの一覧表示]\n");
		printf("タスク一覧:{\n");

		//表示する関数
		Display();

		printf("}\n\n");

		printf("--------------------------------------\n\n");
		printf("1.タスクの表示に戻る\n");
		printf("2.タスクの操作に戻る\n");
		while(number != 1 && number != 2)
		{
			scanf_s("%d", &number);
			scanf_s("%*[^\n]%*c");
		}

		if(number == 1)
		{
			number = 0;
			displayNumber = 0;
		}
		else if(number == 2)
		{
			number = 0;
			displayNumber = 0;
			scene = Scene::INITIAL;
		}

	}
	else if(displayNumber == 2)
	{
		/*int number = 0;
		int listSize = 0;

		printf("\n[順番を指定してタスクを表示]\n");
		printf("表示したいタスクの順番を指定してください。\n");

		printf("タスク一覧:\n");
		printf("{\n\n");
		IndexNumber(&head);
		printf("}\n\n");

		scanf_s("%d", &number);
		scanf_s("%*[^\n]%*c");
		printf("\n");
		printf("--------------------------------------\n");

		displayCell = GetInsertCellAddress(&head, number);
		printf("%5d\n", displayCell->value);

		printf("1.タスクの表示に戻る\n");
		printf("2.タスクの操作に戻る\n");

		while(returnNumber != 1 && returnNumber != 2)
		{
			scanf_s("%d", &returnNumber);
			scanf_s("%*[^\n]%*c");
		}

		if(returnNumber == 1)
		{
			displayNumber = 0;
			returnNumber = 0;
		}
		else if(returnNumber == 2)
		{
			displayNumber = 0;
			scene = Scene::INITIAL;
			returnNumber = 0;
		}*/
	}
	else if(displayNumber == 9)
	{
		displayNumber = 0;
		scene = Scene::INITIAL;
	}
}

void System::InsertUpdate()
{

	//担当者の新規作成
	std::unique_ptr<PIC> newPic = std::make_unique<PIC>();

	newPic->Initialize(taskNum, "testName", PIC::ClassName::LE2A);

	//担当者を登録する
	pics_.push_back(std::move(newPic));


	itrPic_ = pics_.begin();

	/*for(std::unique_ptr<PIC>& pic : pics_)
	{
		pic->Update();
	}*/

	//タスクの新規作成
	std::unique_ptr<Task> newTask = std::make_unique<Task>();

	newTask->Initialize(taskNum, itrPic_->get(), "testTitle", "testContents", Task::Priority::HIGH, 1, false);

	//タスクを登録する
	tasks_.push_back(std::move(newTask));

	taskNum++;
	isAddedTask = false;


	printf("タスクを追加しました\n");

	//ホームに戻る
	ReturnHome();
}

void System::EditUpdate()
{
	int editNumber = 0;
	int changeNumber = 0;
	printf("[タスクの編集]\n");
	printf("変更するタスクIDを指定してください\n");

	for(auto itr = tasks_.begin(); itr != tasks_.end(); ++itr)
	{
		std::cout << "タスクID : " << itr->get()->GetInfo().id << "\n";
	}

	scanf_s("%d", &editNumber);
	scanf_s("%*[^\n]%*c");

	printf("\n");
	printf("\n");
	printf("\n");

	for(auto itr = tasks_.begin(); itr != tasks_.end(); ++itr)
	{
		if(itr->get()->GetInfo().id == editNumber)
		{
			isChanged = true;
		}
	}

	if(isChanged == true)
	{
		for(auto itr = tasks_.begin(); itr != tasks_.end(); ++itr)
		{
			if(itr->get()->GetInfo().id == editNumber)
			{
				printf("--------------------------------------\n");
				std::cout << "現在のステータス : " << itr->get()->GetStatus() << "\n";

				printf("編集するタスクのステータスの値を入力してください。\n\n");
				printf("1 : 完了\n");
				printf("0 : 未完了\n");

				scanf_s("%d", &changeNumber);
				scanf_s("%*[^\n]%*c");
				printf("\n");
				printf("\n");


				itr->get()->SetStatus(changeNumber);

				if(changeNumber == 1)
				{
					printf("ステータスを「完了」に変更しました\n\n");
				}
				else if(changeNumber == 0)
				{
					printf("ステータスを「未完了」に変更しました\n\n");
				}
			}
		}

	}
	else if(isChanged == false)
	{
		printf("一致するIDは見つかりませんでした。\n");
	}

	ReturnHome();
}

void System::Display()
{

	for(auto itr = tasks_.begin(); itr != tasks_.end(); ++itr)
	{
		printf("--------------------------------------\n");

		std::cout << "タスクID : " << itr->get()->GetInfo().id << "\n";

		std::cout << "担当者ID : " << itr->get()->GetInfo().pic->GetPersonIc().id << "\n";
		std::cout << "担当者名 : " << itr->get()->GetInfo().pic->GetPersonIc().name << "\n";
		std::cout << "クラス名 : " << itr->get()->GetInfo().pic->GetPersonIc().className << "\n";

		std::cout << "題名 : " << itr->get()->GetInfo().title << "\n";
		std::cout << "内容 : " << itr->get()->GetInfo().contents << "\n";
		std::cout << "優先度 : " << itr->get()->GetInfo().priority << "\n";
		std::cout << "期限 : " << itr->get()->GetInfo().limit << "日" << "\n";
		std::cout << "ステータス : " << itr->get()->GetInfo().status << "\n";

	}

}

void System::ReturnHome()
{
	printf("9.要素操作に戻る\n");

	//9以外が押された場合は再度入力させる。
	while(returnNumber != 9)
	{
		scanf_s("%d", &returnNumber);
		scanf_s("%*[^\n]%*c");
	}

	if(returnNumber == 9)
	{
		displayNumber = 0;
		scene = Scene::INITIAL;
		returnNumber = 0;
	}
}