#include "Enemy.h"
#include "stdio.h"
#include <windows.h>
#include "time.h"

int Enemy::hp_ = 1;

//staticで宣言したメンバ関数ポインタテーブルの実体
void(Enemy:: *Enemy::spFuncTable[])() =
{
	&Enemy::Move,	//接近
	&Enemy::Attack,	//射撃
	&Enemy::Escape	//離脱
};

//コンストラクタ
Enemy::Enemy()
{
	phase_ = Phase::Approach;
}

Enemy::~Enemy(){}

//接近
void Enemy::Move()
{
	int second = 2;
	printf("状態：近接\n");

	//2秒間待つ
	Sleep(second * 1000);
	//射撃状態に変更
	phase_ = Phase::Shooting;
}

//攻撃
void Enemy::Attack()
{
	int second = 2;
	printf("状態：射撃\n");

	//2秒間待つ
	Sleep(second * 1000);
	//離脱状態に変更
	phase_ = Phase::Leave;
}

//逃走
void Enemy::Escape()
{
	int second = 3;
	printf("状態：離脱\n");

	//3秒間待つ
	Sleep(second * 1000);
	//接近状態に変更
	phase_ = Phase::Approach;
}

//更新
void Enemy::Update()
{
	//デバッグ用表示
	printf("敵の体力 : %d\n", hp_);

	//現在のフェーズの関数を実行
	(this->*spFuncTable[static_cast<size_t>(phase_)])();

}