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

public:

	//初期化
	void Initialize();
	//リスト作成
	void Create(CELL* insertCell, int inputValue);
	//一覧を表示する関数
	void Index(CELL *endCell);
	//更新
	void Update();
	//描画
	void DrawMessage();

	//挿入したいセルのアドレスを取得
	CELL* GetInsertCellAddress(CELL *head,int iterator);

private:

	int iterator;
	int inputValue;
	CELL* insertCell;
	//先頭に内容が空のセルを宣言
	CELL head;
};