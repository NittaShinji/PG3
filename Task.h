#pragma once
#include <list>
#include <string>
#include <memory>
#include "PIC.h"

class Task
{

public:

	//優先度
	enum Priority
	{
		//高
		HIGH = 1,
		//中
		Middle,
		//低
		Low,
	};

private: //列挙型,構造体

	//クラス名
	//enum ClassName
	//{
	//	//プログラマー
	//	LE2A,
	//	LE2B,
	//	LE2C,
	//	LE2D,
	//	//プランナー
	//	LD2A,
	//	LD2B,
	//	LD2C,
	//	LD2D,
	//};

	//担当者(person in charge)
	//struct PIC
	//{
	//	//個人ID
	//	int id;
	//	//氏名
	//	std::string name;
	//	//クラス
	//	ClassName className;
	//};

	//タスク情報
	struct Info
	{
		//タスクID
		int id;
		//担当者
		PIC* pic = nullptr;
		//題名
		std::string title;
		//内容
		std::string contents;
		//優先度
		//Priority priority;
		std::string priority;
		//期限
		int limit;
		//ステータス(未完了/完了)
		//bool status;
		std::string status;
	};

public: //静的関数

	//静的初期化
	static void StaticInitialize();

public: //メンバ関数

	//初期化
	void Initialize(int id, PIC* pic, std::string title, std::string contents, Priority priority, int limit, bool status);

	//更新
	void Update();

	//ステータス変更
	void ChageStatus();

private: //メンバ変数

	//タスク情報
	Info info_;


public:

	
	//ゲッター
	std::string GetStatus() const { return info_.status; }

	Info GetInfo() { return info_; };

	//セッター
	void SetStatus(int changeNumber);

};

