#include "SceneManager.h"

SceneManager::SceneManager()
{
	sceneNo = Title;
	sceneTimer = 60;
}

SceneManager::~SceneManager(){}

SceneManager *SceneManager::GetInstance()
{
	//�֐���static�ϐ��Ƃ��Đ錾
	static SceneManager instance;

	return &instance;
}

void SceneManager::ChangeScene(int sceneNo)
{
	if (sceneTimer <= 0)
	{
		changeCount++;
		if (sceneNo == Title)
		{
			sceneNo = NewGame;
			sceneTimer = 120;
		}
		else if (sceneNo == NewGame)
		{
			sceneNo = GamePlay;
			sceneTimer = 120;
		}
		else if (sceneNo == GamePlay)
		{
			sceneNo = GameClear;
			sceneTimer = 120;
		}
		else if (sceneNo == GameClear)
		{
			sceneNo = Title;
			sceneTimer = 120;
		}
		else {}
	}
	else
	{
		sceneTimer--;
	}
}