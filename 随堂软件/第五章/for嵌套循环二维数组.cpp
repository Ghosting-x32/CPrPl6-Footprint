﻿#include<iostream>
#include<ctime>
const int Cities = 5;
const int Years = 4;
int main()
{
	using namespace std;
	const char* cities[Cities] =
	{
		"Gribble City",
		"Gribbletown",
		"New Gribble",
		"Gribble Vista"
	};
	int maxtemps[Years][Cities] =
	{
		{96, 100, 87, 101, 105},
		{96, 98, 91, 107, 104},
		{97, 101, 93, 108, 107},
		{98, 103, 95, 109, 108}
	};
	cout << "Maximum temperatures for 2008 - 2011\n\n\a";
	for (int city = 0; city < Cities; ++city)
	{
		cout << cities[city] << "\t";
		for (int year = 0; year < Years; ++year)
			cout << maxtemps[year][city] << "\t";
		cout << endl;
	}

	cin.get();
	cin.get();
	return 0;
}