#pragma once

class SceneManager final
{
public:

	//コピーコンストラクタの無効
	SceneManager(const SceneManager& obj) = delete;
	//代入演算子を無効
	SceneManager& operator=(const SceneManager& obj) = delete;
	//インスタンスの生成
	static SceneManager* GetInstance();
	//シーンを切り替える
	void ChangeScene(int sceneNo);

private:

	SceneManager();
	~SceneManager();

	//シーン番号
	int sceneNo_;

public:

	//ゲッター
	int GetSceneNo() { return sceneNo_; };
};
