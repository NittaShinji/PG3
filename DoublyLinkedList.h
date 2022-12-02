#pragma once

//�o�������X�g�̍\����
template <typename T>
struct CELL
{
	T value;
	struct  CELL* prev;
	struct  CELL* next;
};

template <typename T>
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
	void Create(CELL<T>* insertCell, T inputValue);
	//���X�g�폜
	void Delete(CELL<T>* currentCell);

	//�ꗗ��\������֐�
	void Index(CELL<T>*endCell);
	//�ԍ��\��
	void IndexNumber(CELL<T>* endCell);
	//�Ō�̃Z���܂ŉ�
	CELL<T>* MoveEndCell(CELL<T>* endCell);

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
	//�z�[���ɖ߂�
	void ReturnHome();

	//�}���������Z���̃A�h���X���擾
	CELL<T>* GetInsertCellAddress(CELL<T>*head,int iterator);

private:

	//�擪�ɓ��e����̃Z����錾
	CELL<T> head;
	//�C�e���[�^�[
	int iterator;
	
	//�V�[��
	Scene scene;
	//����ԍ�
	int sceneNumber = 0;
	//�\������̔ԍ�
	int displayNumber;
	//����̃z�[����ʂɋA��p�̃L�[�ۑ��ϐ�
	int returnNumber = 0;
	//�I���p�̕ϐ�
	bool isClose;

	//���͂��ꂽ�L�[��������Ȃ��Ƃ��̃t���O
	bool notFindNumber = false;

public:

	//�Q�b�^�[
	bool GetisClose() { return isClose; };

};