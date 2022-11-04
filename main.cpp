#include <stdio.h>
#include <Vector>
#include <list>
#include <iostream>

//全駅を表示
void PrintStation(std::list<const char*>& lst);

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

	//元データから双方向リストを生成
	std::list<const char*> lst(stationName, std::end(stationName));

	printf("1970年駅一覧\n");
	PrintStation(lst);
	printf("\n");

	printf("2019年駅一覧\n");
	std::list<const char*>::iterator itr1971 = std::next(lst.begin(), 7);
	lst.insert(itr1971, "NishiniNippori");
	PrintStation(lst);
	printf("\n");

	printf("2022年駅一覧\n");
	std::list<const char*>::iterator itr2019 = std::next(lst.begin(), 25);
	lst.insert(itr2019, "TakanawaGateway");
	PrintStation(lst);
	printf("\n");

	return 0;
}

//全駅を表示
void PrintStation(std::list<const char*>& lst)
{
	for (auto itr = lst.begin(); itr != lst.end(); ++itr)
	{
		std::cout << *itr << "\n";
	}
}