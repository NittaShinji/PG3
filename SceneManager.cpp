#include "SceneManager.h"

SceneManager::SceneManager()
{
	//������
	sceneNo_ = 0;
}

SceneManager::~SceneManager() {}

SceneManager *SceneManager::GetInstance()
{
	//�֐���static�ϐ��Ƃ��Đ錾
	static SceneManager instance;

	return &instance;
}

void SceneManager::ChangeScene(int sceneNo)
{
	//���������̃V�[���ԍ��ɃV�[����ύX
	sceneNo_ = sceneNo;
}