#include "Enemy.h"

int Enemy::hp_;

//�R���X�g���N�^
Enemy::Enemy()
{
	hp_ = 3;
}

Enemy::~Enemy(){}

//�R�s�[�R���X�g���N�^
Enemy::Enemy(const Enemy &obj)
{
	//HP���R�s�[
	hp_ = obj.hp_;
}

//�G�̗̑͂����炷
void Enemy::DamageEnemy()
{
	//�G��Hp�����炷
	if(hp_ > 0)
	{
		hp_--;
	}
}
