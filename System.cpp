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
	printf("[�^�X�N�̑���]\n");
	printf("1.�^�X�N�̕\��\n");
	printf("2.�^�X�N�̐V�K�쐬\n");

	printf("3.�^�X�N�̕ҏW\n");
	printf("4.�^�X�N�̍폜\n");

	printf("5.�I������\n");
	printf("\n");
	printf("\n");
	printf("--------------------------------------\n");

	printf("����̑I�������Ă�������\n");
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
	//�I�������^�X�N���폜(�v��Ȃ��^�X�N���폜�ł���@�\���~��������)
	/*tasks_.remove_if([](std::unique_ptr<Task>& task)
		{
			return task->GetStatus();
		});*/

		//�^�X�N�X�V
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
		printf("[�^�X�N�̕\��]\n");
		printf("1.�^�X�N�̈ꗗ�\��\n");
		printf("2.���Ԃ��w�肵�ă^�X�N��\��\n");
		printf("9.�^�X�N����ɖ߂�\n");
		printf("\n");
		printf("����̑I�������Ă�������\n");
		while(displayNumber != 1 && displayNumber != 2 && displayNumber != 9)
		{
			scanf_s("%d", &displayNumber);
			scanf_s("%*[^\n]%*c");
		}
	}
	else if(displayNumber == 1)
	{
		int number = 0;
		printf("\n[�^�X�N�̈ꗗ�\��]\n");
		printf("�^�X�N�ꗗ:{\n");

		//�\������֐�
		Display();

		printf("}\n\n");

		printf("--------------------------------------\n\n");
		printf("1.�^�X�N�̕\���ɖ߂�\n");
		printf("2.�^�X�N�̑���ɖ߂�\n");
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

		printf("\n[���Ԃ��w�肵�ă^�X�N��\��]\n");
		printf("�\���������^�X�N�̏��Ԃ��w�肵�Ă��������B\n");

		printf("�^�X�N�ꗗ:\n");
		printf("{\n\n");
		IndexNumber(&head);
		printf("}\n\n");

		scanf_s("%d", &number);
		scanf_s("%*[^\n]%*c");
		printf("\n");
		printf("--------------------------------------\n");

		displayCell = GetInsertCellAddress(&head, number);
		printf("%5d\n", displayCell->value);

		printf("1.�^�X�N�̕\���ɖ߂�\n");
		printf("2.�^�X�N�̑���ɖ߂�\n");

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

	//�S���҂̐V�K�쐬
	std::unique_ptr<PIC> newPic = std::make_unique<PIC>();

	newPic->Initialize(taskNum, "testName", PIC::ClassName::LE2A);

	//�S���҂�o�^����
	pics_.push_back(std::move(newPic));


	itrPic_ = pics_.begin();

	/*for(std::unique_ptr<PIC>& pic : pics_)
	{
		pic->Update();
	}*/

	//�^�X�N�̐V�K�쐬
	std::unique_ptr<Task> newTask = std::make_unique<Task>();

	newTask->Initialize(taskNum, itrPic_->get(), "testTitle", "testContents", Task::Priority::HIGH, 1, false);

	//�^�X�N��o�^����
	tasks_.push_back(std::move(newTask));

	taskNum++;
	isAddedTask = false;


	printf("�^�X�N��ǉ����܂���\n");

	//�z�[���ɖ߂�
	ReturnHome();
}

void System::EditUpdate()
{
	int editNumber = 0;
	int changeNumber = 0;
	printf("[�^�X�N�̕ҏW]\n");
	printf("�ύX����^�X�NID���w�肵�Ă�������\n");

	for(auto itr = tasks_.begin(); itr != tasks_.end(); ++itr)
	{
		std::cout << "�^�X�NID : " << itr->get()->GetInfo().id << "\n";
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
				std::cout << "���݂̃X�e�[�^�X : " << itr->get()->GetStatus() << "\n";

				printf("�ҏW����^�X�N�̃X�e�[�^�X�̒l����͂��Ă��������B\n\n");
				printf("1 : ����\n");
				printf("0 : ������\n");

				scanf_s("%d", &changeNumber);
				scanf_s("%*[^\n]%*c");
				printf("\n");
				printf("\n");


				itr->get()->SetStatus(changeNumber);

				if(changeNumber == 1)
				{
					printf("�X�e�[�^�X���u�����v�ɕύX���܂���\n\n");
				}
				else if(changeNumber == 0)
				{
					printf("�X�e�[�^�X���u�������v�ɕύX���܂���\n\n");
				}
			}
		}

	}
	else if(isChanged == false)
	{
		printf("��v����ID�͌�����܂���ł����B\n");
	}

	ReturnHome();
}

void System::Display()
{

	for(auto itr = tasks_.begin(); itr != tasks_.end(); ++itr)
	{
		printf("--------------------------------------\n");

		std::cout << "�^�X�NID : " << itr->get()->GetInfo().id << "\n";

		std::cout << "�S����ID : " << itr->get()->GetInfo().pic->GetPersonIc().id << "\n";
		std::cout << "�S���Җ� : " << itr->get()->GetInfo().pic->GetPersonIc().name << "\n";
		std::cout << "�N���X�� : " << itr->get()->GetInfo().pic->GetPersonIc().className << "\n";

		std::cout << "�薼 : " << itr->get()->GetInfo().title << "\n";
		std::cout << "���e : " << itr->get()->GetInfo().contents << "\n";
		std::cout << "�D��x : " << itr->get()->GetInfo().priority << "\n";
		std::cout << "���� : " << itr->get()->GetInfo().limit << "��" << "\n";
		std::cout << "�X�e�[�^�X : " << itr->get()->GetInfo().status << "\n";

	}

}

void System::ReturnHome()
{
	printf("9.�v�f����ɖ߂�\n");

	//9�ȊO�������ꂽ�ꍇ�͍ēx���͂�����B
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