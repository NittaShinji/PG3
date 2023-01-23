#include "Enemy.h"

int Enemy::hp_;

//コンストラクタ
Enemy::Enemy()
{
	hp_ = 3;
}

Enemy::~Enemy(){}

//コピーコンストラクタ
Enemy::Enemy(const Enemy &obj)
{
	//HPをコピー
	hp_ = obj.hp_;
}

//敵の体力を減らす
void Enemy::DamageEnemy()
{
	//敵のHpを減らす
	if(hp_ > 0)
	{
		hp_--;
	}
}
