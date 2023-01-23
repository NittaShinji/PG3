#pragma once
class Enemy
{
public:

	//コンストラクタ
	Enemy();
	~Enemy();
	
	//ゲッター
	int GetEnemyHp() { return hp_; };

	//敵の移動
	void Move();
	//敵の攻撃
	void Attack();
	//敵の回避
	void Escape();
	//更新
	void Update();

private:

	//敵の状態フェーズ
	enum class Phase
	{
		Approach,	//近接
		Shooting,	//射撃
		Leave		//離脱
	};

	//メンバ関数ポインタテーブル
	static void(Enemy::*spFuncTable[])();

	//フェーズ
	Phase phase_;
	//敵の体力
	static int hp_;
};

