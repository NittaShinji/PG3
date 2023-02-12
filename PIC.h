#pragma once
#include <string>

class PIC
{

public:

	//クラス名
	enum ClassName
	{
		//プログラマー
		LE2A = 1,
		LE2B,
		LE2C,
		LE2D,
		//プランナー
		LD2A,
		LD2B,
		LD2C,
		LD2D,
	};

	//担当者(person in charge)
	struct PersonIC
	{
		//個人ID
		int id;
		//氏名
		std::string name;
		//クラス
		//ClassName className;
		std::string className;

	};

public: //メンバ関数

	//新規作成
	//初期化
	void Initialize(int id,std::string name,ClassName className);

	//情報の更新
	void Update();

	//タスク側で
	//削除


private:

	PersonIC personIc_;

public: 

	//ゲッター
	PersonIC GetPersonIc() { return personIc_; };
	//セッター
	void SetPicID(int changeId);
	void SetPicName(std::string changePicName);
	void SetPicClassName(int changePicClass);

};