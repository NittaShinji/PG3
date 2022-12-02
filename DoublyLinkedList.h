#pragma once

//双方向リストの構造体
typedef struct CELL
{
	//char name[16]{};
	int value;
	struct  CELL* prev;
	struct  CELL* next;
};

class DoubleList
{	

private:

	enum class Scene
	{
		INITIAL,
		DISPLAY,
		EDIT,
		INSERT,
		DELETE,
		SORT,
		CLOSE,
	};

public:

	//初期化
	void Initialize();
	//全体の更新
	void Update();
	//終了
	void Close();

	//リスト作成
	void Create(CELL* insertCell, int inputValue);
	//リスト削除
	void Delete(CELL* deleteCell);

	//一覧を表示する関数
	void Index(CELL *endCell);

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
	void DeleteUpdate();
	//並び替え
	void SortUpdate();

	void ReturnHome();

	//描画
	void DrawMessage();
	void DisplayComponents();

	//挿入したいセルのアドレスを取得
	CELL* GetInsertCellAddress(CELL *head,int iterator);

private:

	bool isClose;
	bool isWorked;
	int iterator;
	int inputValue;
	Scene scene;
	CELL* insertCell;
	//先頭に内容が空のセルを宣言
	CELL head;

	CELL* displayCell;
	

	int sceneNumber = 0;
	//int InputSceneNum;
	int displayNumber;

	//ホームに帰る用のキー保存変数
	int returnNumber = 0;

	bool notFindNumber = false;

	//追加する場所の数
	int insertNum = 0;
	//追加する要素
	int value = 0;


public:

	bool GetisClose() { return isClose; };

};