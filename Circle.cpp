#include "Circle.h"

//–ÊÏ‚ğ‹‚ß‚é
void Circle::Size()
{
	area =  r * r * PI;
}

//–ÊÏ‚ğ•\¦
void Circle::Draw()
{
	printf("%f\n", area);
}
