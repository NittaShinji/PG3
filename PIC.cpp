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
	
}
