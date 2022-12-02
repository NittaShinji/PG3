#pragma once

//双方向リストの構造体
template <typename T>
struct CELL
{
	T value;
	struct  CELL* prev;
	struct  CELL* next;
};

template <typename T>
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
	void Create(CELL<T>* insertCell, T inputValue);
	//リスト削除
	void Delete(CELL<T>* currentCell);

	//一覧を表示する関数
	void Index(CELL<T>*endCell);
	//番号表示
	void IndexNumber(CELL<T>* endCell);
	//最後のセルまで回す
	CELL<T>* MoveEndCell(CELL<T>* endCell);

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
	//ホームに戻る
	void ReturnHome();

	//挿入したいセルのアドレスを取得
	CELL<T>* GetInsertCellAddress(CELL<T>*head,int iterator);

private:

	//先頭に内容が空のセルを宣言
	CELL<T> head;
	//イテレーター
	int iterator;
	
	//シーン
	Scene scene;
	//操作番号
	int sceneNumber = 0;
	//表示操作の番号
	int displayNumber;
	//操作のホーム画面に帰る用のキー保存変数
	int returnNumber = 0;
	//終了用の変数
	bool isClose;

	//入力されたキーが見つからないときのフラグ
	bool notFindNumber = false;

public:

	//ゲッター
	bool GetisClose() { return isClose; };

};