#pragma once
class Enemy
{
public:

	//�R���X�g���N�^
	Enemy();
	~Enemy();
	
	//�Q�b�^�[
	int GetEnemyHp() { return hp_; };

	//�G�̈ړ�
	void Move();
	//�G�̍U��
	void Attack();
	//�G�̉��
	void Escape();
	//�X�V
	void Update();

private:

	//�G�̏�ԃt�F�[�Y
	enum class Phase
	{
		Approach,	//�ߐ�
		Shooting,	//�ˌ�
		Leave		//���E
	};

	//�����o�֐��|�C���^�e�[�u��
	static void(Enemy::*spFuncTable[])();

	//�t�F�[�Y
	Phase phase_;
	//�G�̗̑�
	static int hp_;
};

