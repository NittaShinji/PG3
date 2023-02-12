#include "Task.h"

void Task::Initialize(int id, PIC* pic, std::string title, std::string contents, Priority priority, int limit, bool status)
{
	//ƒ^ƒXƒNî•ñ‚Ì‰Šú‰»
	info_.id = id;
	info_.pic = pic;
	info_.title = title;
	info_.contents = contents;
	info_.priority = priority;
	info_.limit = limit;
	info_.status = status;
}

void Task::Update()
{
	
}

void Task::ChageStatus()
{
	info_.status = false;
}

void Task::SetStatus(int changeNumber)
{
	if(changeNumber == 0)
	{
		info_.status = false;
	}
	else if(changeNumber == 1)
	{
		info_.status = true;
	}
	else
	{}
}

