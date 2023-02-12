#include "Task.h"

void Task::Initialize(int id, PIC* pic, std::string title, std::string contents, Priority priority, int limit, bool status)
{
	//ƒ^ƒXƒNî•ñ‚Ì‰Šú‰»
	info_.id = id;
	info_.pic = pic;
	info_.title = title;
	info_.contents = contents;

	if(priority == 1)
	{
		info_.priority = "HIGH";
	}
	if(priority == 2)
	{
		info_.priority = "Middle";
	}
	if(priority == 3)
	{
		info_.priority = "Low";
	}
	
	info_.limit = limit;
	//info_.status = status;
	if(status == 0)
	{
		info_.status = "–¢Š®—¹";
	}
	if(status == 1)
	{
		info_.status = "Š®—¹";
	}
}

void Task::Update()
{
	
}

void Task::ChageStatus()
{
	info_.status = "–¢Š®—¹";
}

void Task::SetStatus(int changeNumber)
{
	if(changeNumber == 0)
	{
		info_.status = "–¢Š®—¹";
	}
	else if(changeNumber == 1)
	{
		info_.status = "Š®—¹";
	}
	else
	{}
}

