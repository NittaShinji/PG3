#pragma once

class SceneManager final
{
public:
	//コピーコンストラクタの無効
	SceneManager(const SceneManager& obj) = delete;
	//代入演算子を無効
	SceneManager& operator=(const SceneManager& obj) = delete;

	static SceneManager* GetInstance();

	void ChangeScene(int sceneNo);

	int GetChangeCount() { return changeCount; };

private:

	enum Scene
	{
		Title = 0,
		NewGame,
		GamePlay,
		GameClear,
	};

	SceneManager();
	~SceneManager();

	int sceneTimer;
	int sceneNo;
	int changeCount;

};
