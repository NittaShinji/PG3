#include <stdio.h>
#include <Vector>
#include <list>
#include <iostream>

int main()
{
	//駅数(路線記号[JY])
	const int JY = 28;

	const char* stationName[JY] =
	{ "Tokyo", "Kanda", "Akihabara", "Okachimachi", "Ueno",
	"Uguisudani", "Nippori", "Tabata", "Komagome","Sugamo",
	"Otsuka", "Ikebukuro", "Mejiro", "Takadanobaba",
	"ShinOkubo", "Shinjuku", "Yoyogi", "Harajuku", "Shibuya",
	"Ebisu", "Meguro", "Gotanda", "Osaki", "Shinagawa",
	"Tamachi", "Hamamatsucho","Shimbashi", "Yurakucho"};

	//char stationName2 = { 'a'};

	//元データから双方向リストを生成
	std::list<const char*> lstJY(stationName, std::end(stationName));

	//std::list<char>::iterator itr

	//リストにはオペレーターがなく、大きさ比較できないので<>は使えない
	for (auto itr = lstJY.begin(); itr != lstJY.end(); ++itr)
	{
		std::cout << *itr << "\n";
	}

	//printf("%s\n", stationName[1]);


	
	/*std::list<int> it = { 1,2,4 };
	
	std::list<int>::iterator itr = std::next(it.begin(), 2);
	it.insert(itr, 3);
	
	for (auto itr = it.begin(); itr != it.end(); itr++)
	{
		std::cout << *itr << "\n";
	}*/


	return 0;
}