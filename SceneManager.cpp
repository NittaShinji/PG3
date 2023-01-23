#include "SceneManager.h"

SceneManager::SceneManager()
{
	//初期化
	sceneNo_ = 0;
}

SceneManager::~SceneManager() {}

SceneManager *SceneManager::GetInstance()
{
	//関数内static変数として宣言
	static SceneManager instance;

	return &instance;
}

void SceneManager::ChangeScene(int sceneNo)
{
	//受取った次のシーン番号にシーンを変更
	sceneNo_ = sceneNo;
}