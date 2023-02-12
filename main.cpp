#include"stdio.h"
#include "windows.h"
#include "System.h"
#include <memory>

int main()
{
	//�V�X�e���̐���
	std::unique_ptr<System> system_ = std::make_unique<System>();
	//�V�X�e���̏�����
	system_->Initialize();

	while(true)
	{
		//�V�X�e���̍X�V
		system_->Update();
		//�I�����邩�ǂ���
		if(system_->GetisClose())
		{
			break;
		}
	}

	system("PAUSE");
	return 0;
}