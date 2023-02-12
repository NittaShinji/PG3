#pragma once
#include <list>
#include <string>
#include <memory>
#include "Task.h"

class System
{

public:
	
	//初期化
	void Initialize();

	//内部情報の更新
	void Update();

	//タスクの新規作成
	void NewTask();
	//ステータスの変更
	void ChangeStatus();

	//表示
	void Display();

	////要素項目の関数
	//初期画面
	void InitialUpdate();
	//要素の表示
	void DisplayUpdate();
	//編集
	void EditUpdate();
	//挿入
	void InsertUpdate();
	//削除
	//void DeleteUpdate();
	//並び替え
	//void SortUpdate();
	//ホームに戻る
	void ReturnHome();

private:

	//シーン
	enum class Scene
	{
		INITIAL,
		DISPLAY,
		EDIT,
		INSERT,
		//DELETE,
		SORT,

		CLOSE,
	};

	//シーン
	Scene scene;
	//タスク
	std::list<std::unique_ptr<Task>> tasks_;
	//担当者
	std::list<std::unique_ptr<PIC>> pics_;


	std::list<std::unique_ptr<Task>>::iterator itrTask_;
	std::list<std::unique_ptr<PIC>>::iterator itrPic_;

	//操作番号
	int sceneNumber = 0;
	//表示操作の番号
	int displayNumber;
	//タスク追加用の管理フラグ
	bool isAddedTask;
	//タスクの個数
	int taskNum;
	//終了用の変数
	bool isClose;
	//操作のホーム画面に帰る用のキー保存変数
	int returnNumber = 0;
	//入力されたキーが見つからないときのフラグ
	bool notFindNumber = false;

	bool isChanged = false;


public:

	//ゲッター
	bool GetisClose() { return isClose; };
};