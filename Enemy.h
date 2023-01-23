#pragma once
class Enemy
{
public:

	//コンストラクタ
	Enemy();
	~Enemy();
	
	//コピーコンストラクタ
	Enemy(const Enemy &obj);
	//ゲッター
	int GetEnemyHp() { return hp_; };
	//敵の体力を減らす
	void DamageEnemy();

private:

	//敵の体力
	static int hp_;
};

