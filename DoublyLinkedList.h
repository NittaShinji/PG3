#pragma once

//�o�������X�g�̍\����
typedef struct CELL
{
	//char name[16]{};
	int value;
	struct  CELL* prev;
	struct  CELL* next;
};

class DoubleList
{	

private:

	enum class Scene
	{
		INITIAL,
		DISPLAY,
		EDIT,
		INSERT,
		DELETE,
		SORT,
		CLOSE,
	};

public:

	//������
	void Initialize();
	//�S�̂̍X�V
	void Update();
	//�I��
	void Close();

	//���X�g�쐬
	void Create(CELL* insertCell, int inputValue);
	//���X�g�폜
	void Delete(CELL* deleteCell);

	//�ꗗ��\������֐�
	void Index(CELL *endCell);

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
	void DeleteUpdate();
	//���ёւ�
	void SortUpdate();

	void ReturnHome();

	//�`��
	void DrawMessage();
	void DisplayComponents();

	//�}���������Z���̃A�h���X���擾
	CELL* GetInsertCellAddress(CELL *head,int iterator);

private:

	bool isClose;
	bool isWorked;
	int iterator;
	int inputValue;
	Scene scene;
	CELL* insertCell;
	//�擪�ɓ��e����̃Z����錾
	CELL head;

	CELL* displayCell;
	

	int sceneNumber = 0;
	//int InputSceneNum;
	int displayNumber;

	//�z�[���ɋA��p�̃L�[�ۑ��ϐ�
	int returnNumber = 0;

	bool notFindNumber = false;

	//�ǉ�����ꏊ�̐�
	int insertNum = 0;
	//�ǉ�����v�f
	int value = 0;


public:

	bool GetisClose() { return isClose; };

};