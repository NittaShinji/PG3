#pragma once
class Enemy
{
public:

	//�R���X�g���N�^
	Enemy();
	~Enemy();
	
	//�R�s�[�R���X�g���N�^
	Enemy(const Enemy &obj);
	//�Q�b�^�[
	int GetEnemyHp() { return hp_; };
	//�G�̗̑͂����炷
	void DamageEnemy();

private:

	//�G�̗̑�
	static int hp_;
};

