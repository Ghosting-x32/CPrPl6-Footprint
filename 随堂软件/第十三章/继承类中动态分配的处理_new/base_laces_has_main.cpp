﻿#include <iostream>
#include<string>

#include"baseDMA.h"
#include"hasDMA.h"
#include"lacksDMA.h"




using namespace std;



int main()
{
	baseDMA shirt("Portabelly", 8);
	lacksDMA balloon("red", "Blimpo", 4);
	hasDMA map("Mercator", "Buffalo Keys", 5);

	cout << "Displaying baseDMA object:\n";
	cout << shirt << endl;

	cout << "Displaying lacksDMA object:\n";
	cout << balloon << endl;

	cout << "Displaying hasDMA object:\n";
	cout << map << endl;

	lacksDMA balloon2(balloon);
	cout << "Result of lacksDMA copy:\n";
	cout << balloon2 << endl;

	hasDMA map2;
	map2 = map;
	cout << "Result of hasDMA assignment:\n";
	cout << map2 << endl;

	

	system("pause");
	return 0;
}

