#include "PIC.h"
#include "Task.h"

void PIC::Initialize(int id, std::string name, ClassName className)
{
	personIc_.id = id;
	personIc_.name = name;
	if(className == 1)
	{
		personIc_.className = "LE2A";
	}
	if(className == 2)
	{
		personIc_.className = "LE2B";
	}
	if(className == 3)
	{
		personIc_.className = "LE2C";
	}
	if(className == 4)
	{
		personIc_.className = "LE2D";
	}
	if(className == 0)
	{
		personIc_.className = "----";
	}

}

void PIC::SetPicID(int changeId)
{
	personIc_.id = changeId;
}
void PIC::SetPicName(std::string changePicName)
{
	personIc_.name = changePicName;
}
void PIC::SetPicClassName(int changePicClass)
{
	if(changePicClass == 1)
	{
		personIc_.className = "LE2A";
	}
	if(changePicClass == 2)
	{
		personIc_.className = "LE2B";
	}
	if(changePicClass == 3)
	{
		personIc_.className = "LE2C";
	}
	if(changePicClass == 4)
	{
		personIc_.className = "LE2D";
	}
	if(changePicClass == 0)
	{
		personIc_.className = "----";
	}

}
