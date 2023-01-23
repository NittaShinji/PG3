#include "stdio.h"
#include "stdlib.h"
#include <windows.h>
#include "time.h"
#include "SceneManager.h"


int main()
{
	//�C���X�^���X�̎擾
	SceneManager* sceneManager = SceneManager::GetInstance();

	//�V�[���ԍ�
	int sceneNo = 0;
	//�҂b��
	const int second = 2;

	while (true)
	{
		//�g�p
		sceneManager->ChangeScene(sceneNo);
		//�\��
		printf("%d\n", sceneManager->GetSceneNo());
		//���[�v����
		if(sceneNo < 4)
		{
			sceneNo++;
		}
		else
		{
			sceneNo = 0;
		}
		//2�b�ԑ҂�
		Sleep(second * 1000);
	}
	
	system("PAUSE");
	return 0;
}

	