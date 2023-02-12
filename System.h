#pragma once
#include <list>
#include <string>
#include <memory>
#include "Task.h"

class System
{

public:
	
	//������
	void Initialize();

	//�������̍X�V
	void Update();

	//�^�X�N�̐V�K�쐬
	void NewTask();
	//�X�e�[�^�X�̕ύX
	void ChangeStatus();

	//�\��
	void Display();

	////�v�f���ڂ̊֐�
	//�������
	void InitialUpdate();
	//�v�f�̕\��
	void DisplayUpdate();
	//�ҏW
	void EditUpdate();
	//�}��
	void InsertUpdate();
	//�폜
	//void DeleteUpdate();
	//���ёւ�
	//void SortUpdate();
	//�z�[���ɖ߂�
	void ReturnHome();

private:

	//�V�[��
	enum class Scene
	{
		INITIAL,
		DISPLAY,
		EDIT,
		INSERT,
		//DELETE,
		SORT,

		CLOSE,
	};

	//�V�[��
	Scene scene;
	//�^�X�N
	std::list<std::unique_ptr<Task>> tasks_;
	//�S����
	std::list<std::unique_ptr<PIC>> pics_;


	std::list<std::unique_ptr<Task>>::iterator itrTask_;
	std::list<std::unique_ptr<PIC>>::iterator itrPic_;

	//����ԍ�
	int sceneNumber = 0;
	//�\������̔ԍ�
	int displayNumber;
	//�^�X�N�ǉ��p�̊Ǘ��t���O
	bool isAddedTask;
	//�^�X�N�̌�
	int taskNum;
	//�I���p�̕ϐ�
	bool isClose;
	//����̃z�[����ʂɋA��p�̃L�[�ۑ��ϐ�
	int returnNumber = 0;
	//���͂��ꂽ�L�[��������Ȃ��Ƃ��̃t���O
	bool notFindNumber = false;

	bool isChanged = false;


public:

	//�Q�b�^�[
	bool GetisClose() { return isClose; };
};