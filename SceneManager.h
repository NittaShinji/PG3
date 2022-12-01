#pragma once

class SceneManager final
{
public:
	//�R�s�[�R���X�g���N�^�̖���
	SceneManager(const SceneManager& obj) = delete;
	//������Z�q�𖳌�
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
