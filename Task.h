#pragma once
#include <list>
#include <string>
#include <memory>
#include "PIC.h"

class Task
{

public:

	//�D��x
	enum Priority
	{
		//��
		HIGH = 1,
		//��
		Middle,
		//��
		Low,
	};

private: //�񋓌^,�\����

	//�N���X��
	//enum ClassName
	//{
	//	//�v���O���}�[
	//	LE2A,
	//	LE2B,
	//	LE2C,
	//	LE2D,
	//	//�v�����i�[
	//	LD2A,
	//	LD2B,
	//	LD2C,
	//	LD2D,
	//};

	//�S����(person in charge)
	//struct PIC
	//{
	//	//�lID
	//	int id;
	//	//����
	//	std::string name;
	//	//�N���X
	//	ClassName className;
	//};

	//�^�X�N���
	struct Info
	{
		//�^�X�NID
		int id;
		//�S����
		PIC* pic = nullptr;
		//�薼
		std::string title;
		//���e
		std::string contents;
		//�D��x
		//Priority priority;
		std::string priority;
		//����
		int limit;
		//�X�e�[�^�X(������/����)
		//bool status;
		std::string status;
	};

public: //�ÓI�֐�

	//�ÓI������
	static void StaticInitialize();

public: //�����o�֐�

	//������
	void Initialize(int id, PIC* pic, std::string title, std::string contents, Priority priority, int limit, bool status);

	//�X�V
	void Update();

	//�X�e�[�^�X�ύX
	void ChageStatus();

private: //�����o�ϐ�

	//�^�X�N���
	Info info_;


public:

	
	//�Q�b�^�[
	std::string GetStatus() const { return info_.status; }

	Info GetInfo() { return info_; };

	//�Z�b�^�[
	void SetStatus(int changeNumber);

};

