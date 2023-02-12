#include"stdio.h"
#include "windows.h"
#include "System.h"
#include <memory>

int main()
{
	//システムの生成
	std::unique_ptr<System> system_ = std::make_unique<System>();
	//システムの初期化
	system_->Initialize();

	while(true)
	{
		//システムの更新
		system_->Update();
		//終了するかどうか
		if(system_->GetisClose())
		{
			break;
		}
	}

	system("PAUSE");
	return 0;
}