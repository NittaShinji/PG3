#include "System.h"
#include <iostream>
#include <iomanip>

void System::Initialize()
{
	scene = Scene::INITIAL;
	isClose = false;
	isAddedTask = true;
	taskNum = 1;
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
		scene = Scene::EDITDELETE;
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

	case Scene::EDITDELETE:

		DeleteUpdate();
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
	else if(displayNumber == 9)
	{
		displayNumber = 0;
		scene = Scene::INITIAL;
		returnNumber = 0;
	}
	else
	{
		ReturnHome();
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
	int editIDNumber = 0;
	int changeNumber = 0;
	bool changeEdit = false;
	int changeEditNum = 0;
	int setPicEditNum = 0;
	int changePicId = 0;
	char setName[20];
	std::string changePicName;
	int changePicClass = 0;


	printf("�ҏW���������̂�I�����Ă�������\n");
	printf("1 : [�S���҂̕ҏW]\n");
	printf("2 : [�^�X�N�̕ҏW]\n");

	scanf_s("%d", &changeEditNum);
	scanf_s("%*[^\n]%*c");



	if(changeEditNum == 1)
	{
		printf("�ύX����S���҂�ID���w�肵�Ă�������\n");

		for(auto itr = tasks_.begin(); itr != tasks_.end(); ++itr)
		{
			std::cout << "�S����ID : " << itr->get()->GetInfo().pic->GetPersonIc().id << "\n";
		}
		scanf_s("%d", &editIDNumber);
		scanf_s("%*[^\n]%*c");

		printf("\n");
		printf("\n");
		printf("\n");

		for(auto itr = tasks_.begin(); itr != tasks_.end(); ++itr)
		{
			if(itr->get()->GetInfo().pic->GetPersonIc().id == editIDNumber)
			{
				isChanged = true;
			}
		}

		printf("�ҏW���������̂�I�����Ă�������\n");
		printf("1 : [�S���҂�ID]\n");
		printf("2 : [�S���҂̎���]\n");
		printf("3 : [�S���҂̃N���X]\n");

		scanf_s("%d", &setPicEditNum);
		scanf_s("%*[^\n]%*c");


		if(isChanged == true)
		{
#pragma region �S����ID
			if(setPicEditNum == 1)
			{
				for(auto itr = tasks_.begin(); itr != tasks_.end(); ++itr)
				{
					if(itr->get()->GetInfo().pic->GetPersonIc().id == editIDNumber)
					{
						printf("--------------------------------------\n");
						std::cout << "���݂̒S����ID : " << itr->get()->GetInfo().pic->GetPersonIc().id << "\n";

						printf("�S����ID��ύX���܂�\n");
						printf("�ҏW����S���҂�ID����͂��Ă��������B\n\n");

						scanf_s("%d", &changePicId);
						scanf_s("%*[^\n]%*c");
						printf("\n");
						printf("\n");


						itr->get()->GetInfo().pic->SetPicID(changePicId);

						
						printf("�S����ID��ύX���܂���\n\n");
						std::cout << "���݂̒S����ID : " << itr->get()->GetInfo().pic->GetPersonIc().id << "\n";
					}
				}
			}
#pragma endregion
			else if(setPicEditNum == 2)
			{
				for(auto itr = tasks_.begin(); itr != tasks_.end(); ++itr)
				{
					if(itr->get()->GetInfo().pic->GetPersonIc().id == editIDNumber)
					{
						printf("--------------------------------------\n");
						std::cout << "���݂̒S���҂̖��O : " << itr->get()->GetInfo().pic->GetPersonIc().name << "\n";

						printf("�S���҂̖��O��ύX���܂�\n");
						printf("�ύX��̒S���҂̖��O����͂��Ă��������B\n\n");

						scanf_s("%s", setName,20);
						//scanf_s("%*[^\n]%*c");
						printf("\n");
						printf("\n");

						changePicName = setName;

						itr->get()->GetInfo().pic->SetPicName(changePicName);

						printf("�S���҂̖��O��ύX���܂���\n\n");
						std::cout << "���݂̒S���҂̖��O : " << itr->get()->GetInfo().pic->GetPersonIc().name << "\n";
					}
				}
			}
			else if(setPicEditNum == 3)
			{
				for(auto itr = tasks_.begin(); itr != tasks_.end(); ++itr)
				{
					if(itr->get()->GetInfo().pic->GetPersonIc().id == editIDNumber)
					{
						printf("--------------------------------------\n");
						std::cout << "���݂̒S���҂̃N���X : " << itr->get()->GetInfo().pic->GetPersonIc().className << "\n";

						printf("�S���҂̃N���X��ύX���܂�\n");
						printf("�ύX��̒S���҂̃N���X�̔ԍ�����͂��Ă��������B\n\n");
						printf("1 : [LE2A]\n");
						printf("2 : [LE2B]\n");
						printf("3 : [LE2C]\n");
						printf("4 : [LE2D]\n");

						scanf_s("%d", &changePicClass);
						//scanf_s("%*[^\n]%*c");
						printf("\n");
						printf("\n");

						itr->get()->GetInfo().pic->SetPicClassName(changePicClass);

						printf("�S���҂̃N���X��ύX���܂���\n\n");
						std::cout << "���݂̒S���҂̃N���X : " << itr->get()->GetInfo().pic->GetPersonIc().className << "\n";
					}
				}
			}
		}
		else if(isChanged == false)
		{
			printf("��v����ID�͌�����܂���ł����B\n");
		}
	}



	if(changeEditNum == 2)
	{
		printf("�ύX����^�X�NID���w�肵�Ă�������\n");

		for(auto itr = tasks_.begin(); itr != tasks_.end(); ++itr)
		{
			std::cout << "�^�X�NID : " << itr->get()->GetInfo().id << "\n";
		}

		scanf_s("%d", &editIDNumber);
		scanf_s("%*[^\n]%*c");

		printf("\n");
		printf("\n");
		printf("\n");

		for(auto itr = tasks_.begin(); itr != tasks_.end(); ++itr)
		{
			if(itr->get()->GetInfo().id == editIDNumber)
			{
				isChanged = true;
			}
		}

		if(isChanged == true)
		{
			for(auto itr = tasks_.begin(); itr != tasks_.end(); ++itr)
			{
				if(itr->get()->GetInfo().id == editIDNumber)
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
	}
	

	ReturnHome();
}

void System::DeleteUpdate()
{

	int editIDNumber = 0;
	int setPicEditNum = 0;
	int changeNumber = 0;
	bool changeEdit = false;
	int changeEditNum = 0;
	
	int changePicId = 0;
	char setName[20];
	std::string changePicName;
	int changePicClass = 0;

	printf("�폜���������̂�I�����Ă�������\n");
	printf("1 : [�S���҂̍폜]\n");
	printf("2 : [�^�X�N�̍폜]\n");

	scanf_s("%d", &changeEditNum);
	scanf_s("%*[^\n]%*c");

	if(changeEditNum == 1)
	{
		printf("�S���҂̍폜���s���܂�\n");

		printf("�폜����S���҂�ID���w�肵�Ă�������\n");

		for(auto itr = tasks_.begin(); itr != tasks_.end(); ++itr)
		{
			std::cout << "�S����ID : " << itr->get()->GetInfo().pic->GetPersonIc().id << "\n";
		}
		scanf_s("%d", &editIDNumber);
		scanf_s("%*[^\n]%*c");

		printf("\n");
		printf("\n");
		printf("\n");

		for(auto itr = tasks_.begin(); itr != tasks_.end(); ++itr)
		{
			if(itr->get()->GetInfo().pic->GetPersonIc().id == editIDNumber)
			{
				isChanged = true;
			}
		}

		printf("�폜���������̂�I�����Ă�������\n");
		printf("1 : [�S���҂�ID]\n");
		printf("2 : [�S���҂̎���]\n");
		printf("3 : [�S���҂̃N���X]\n");

		scanf_s("%d", &setPicEditNum);
		scanf_s("%*[^\n]%*c");

		if(isChanged == true)
		{
#pragma region �S����ID
			if(setPicEditNum == 1)
			{
				for(auto itr = tasks_.begin(); itr != tasks_.end(); ++itr)
				{
					if(itr->get()->GetInfo().pic->GetPersonIc().id == editIDNumber)
					{
						printf("--------------------------------------\n");
						std::cout << "���݂̒S����ID : " << itr->get()->GetInfo().pic->GetPersonIc().id << "\n";

						printf("�S����ID���폜���܂�\n");
						
						printf("\n");
						printf("\n");

						changePicId = 0;

						itr->get()->GetInfo().pic->SetPicID(changePicId);


						printf("�S����ID��ύX���܂���\n\n");
						std::cout << "���݂̒S����ID : " << itr->get()->GetInfo().pic->GetPersonIc().id << "\n";
					}
				}
			}
#pragma endregion
			else if(setPicEditNum == 2)
			{
				for(auto itr = tasks_.begin(); itr != tasks_.end(); ++itr)
				{
					if(itr->get()->GetInfo().pic->GetPersonIc().id == editIDNumber)
					{
						printf("--------------------------------------\n");
						std::cout << "���݂̒S���҂̖��O : " << itr->get()->GetInfo().pic->GetPersonIc().name << "\n";

						printf("�S���҂̖��O���폜���܂�\n");
						
						changePicName = "--------";

						itr->get()->GetInfo().pic->SetPicName(changePicName);

						printf("�S���҂̖��O��ύX���܂���\n\n");
						std::cout << "���݂̒S���҂̖��O : " << itr->get()->GetInfo().pic->GetPersonIc().name << "\n";
					}
				}
			}
			else if(setPicEditNum == 3)
			{
				for(auto itr = tasks_.begin(); itr != tasks_.end(); ++itr)
				{
					if(itr->get()->GetInfo().pic->GetPersonIc().id == editIDNumber)
					{
						printf("--------------------------------------\n");
						std::cout << "���݂̒S���҂̃N���X : " << itr->get()->GetInfo().pic->GetPersonIc().className << "\n";

						printf("�S���҂̃N���X���폜���܂�\n");
						
						changePicClass = 0;

						itr->get()->GetInfo().pic->SetPicClassName(changePicClass);

						printf("�S���҂̃N���X��ύX���܂���\n\n");
						std::cout << "���݂̒S���҂̃N���X : " << itr->get()->GetInfo().pic->GetPersonIc().className << "\n";
					}
				}
			}
		}
		else if(isChanged == false)
		{
			printf("��v����ID�͌�����܂���ł����B\n");
		}

	}
	if(changeEditNum == 2)
	{
		printf("�^�X�N�̍폜���s���܂�\n");
		printf("���̃v���O�����͖������ł�\n");
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