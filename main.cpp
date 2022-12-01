#include "stdio.h"
#include "stdlib.h"
#include "string.h"

//�P�������X�g�̍\���̂��`
typedef struct Cell
{
	char name[16];
	int lendDate;
	int returnDate;
	struct Cell* next;
}; 

//�f�[�^��ǉ�����֐�
void Create(Cell* head, const char* buf);
//�ꗗ��\������֐�
void Index(Cell *head);

#include "SceneManager.h"

int main()
{
	//�C���X�^���X�̎擾
	SceneManager* sceneManager = SceneManager::GetInstance();

	int sceneNo = 0;
	int changeCount = 0;

	while (changeCount < 100)
	{
		changeCount = sceneManager->GetChangeCount();
		//�g�p
		sceneManager->ChangeScene(sceneNo);

		printf("%d\n", changeCount);
		printf("%d\n", sceneNo);

	}
	
	system("PAUSE");
	return 0;
}
