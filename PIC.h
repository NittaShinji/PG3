#pragma once
#include <string>

class PIC
{

public:

	//�N���X��
	enum ClassName
	{
		//�v���O���}�[
		LE2A = 1,
		LE2B,
		LE2C,
		LE2D,
		//�v�����i�[
		LD2A,
		LD2B,
		LD2C,
		LD2D,
	};

	//�S����(person in charge)
	struct PersonIC
	{
		//�lID
		int id;
		//����
		std::string name;
		//�N���X
		//ClassName className;
		std::string className;

	};

public: //�����o�֐�

	//�V�K�쐬
	//������
	void Initialize(int id,std::string name,ClassName className);

	//���̍X�V
	void Update();

	//�^�X�N����
	//�폜


private:

	PersonIC personIc_;

public: 

	//�Q�b�^�[
	PersonIC GetPersonIc() { return personIc_; };
	//�Z�b�^�[
	void SetPicID(int changeId);
	void SetPicName(std::string changePicName);
	void SetPicClassName(int changePicClass);

};