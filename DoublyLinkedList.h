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

public:

	//������
	void Initialize();
	//���X�g�쐬
	void Create(CELL* insertCell, int inputValue);
	//�ꗗ��\������֐�
	void Index(CELL *endCell);
	//�X�V
	void Update();
	//�`��
	void DrawMessage();

	//�}���������Z���̃A�h���X���擾
	CELL* GetInsertCellAddress(CELL *head,int iterator);

private:

	int iterator;
	int inputValue;
	CELL* insertCell;
	//�擪�ɓ��e����̃Z����錾
	CELL head;
};