﻿#include <iostream>//char数组的缺陷
int main()
{
	using namespace std;
	const int ArSize = 15;
	char name[ArSize];
	char dessert[ArSize];

	cout << "Enter your name:\n";
	cin >> name;
	cout << "Enter your favorite dessert:\n";
	cin >> dessert;
	cout << "I have some delicious " << dessert;
	cout << " for you, " << name << ".\n";
	cin.get();
	cin.get();
	return 0;
}
