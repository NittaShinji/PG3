#pragma once

class SceneManager final
{
public:

	//�R�s�[�R���X�g���N�^�̖���
	SceneManager(const SceneManager& obj) = delete;
	//������Z�q�𖳌�
	SceneManager& operator=(const SceneManager& obj) = delete;
	//�C���X�^���X�̐���
	static SceneManager* GetInstance();
	//�V�[����؂�ւ���
	void ChangeScene(int sceneNo);

private:

	SceneManager();
	~SceneManager();

	//�V�[���ԍ�
	int sceneNo_;

public:

	//�Q�b�^�[
	int GetSceneNo() { return sceneNo_; };
};
