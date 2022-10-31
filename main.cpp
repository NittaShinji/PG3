#include <stdio.h>
#include <Vector>
#include <list>
#include <iostream>

int main()
{
	//駅数(路線記号[JY])
	const int JY = 28;

	char stationName[JY][20] =
	{ "Tokyo", "Kanda", "Akihabara", "Okachimachi", "Ueno",
	"Uguisudani", "Nippori", "Tabata", "Komagome","Sugamo",
	"Otsuka", "Ikebukuro", "Mejiro", "Takadanobaba",
	"ShinOkubo", "Shinjuku", "Yoyogi", "Harajuku", "Shibuya",
	"Ebisu", "Meguro", "Gotanda", "Osaki", "Shinagawa",
	"Tamachi", "Hamamatsuchō","Shimbashi", "Yurakucho" };

	//元データから双方向リストを生成
	std::list<char> lstJY(stationName,std::end(stationName));

	std::list<char>::iterator itr;

	//リストにはオペレーターがなく、大きさ比較できないので<>は使えない
	for (auto itr = lstJY.begin(); itr != lstJY.end(); ++itr)
	{
		std::cout << *itr << "\n";
	}
	
	return 0;
}