﻿#include<iostream>
#include "coordin.h"
using namespace std;

int main()
{
	using namespace std;
	rect rplace;
	polar pplace;
	cout << "Enter the x and y values: ";
	while (cin >> rplace.x >> rplace.y)
	{
		pplace = rect_to_polar(rplace);
		show_polar(pplace);
		cout << "Next two numbers (q to quit): ";
	}
	cout << "Done.\a\a\n";


	system("pause");
	return 0;
}
