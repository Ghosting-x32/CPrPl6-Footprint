#include<iostream>
#include<string>

#include"Port.h"
#include"VintagePort.h"

using namespace std;

int main()
{
	Port por1("Gallo", "tawny", 20);
	por1.Show();

	Port por2;
	por2 = por1;
	por2 -= 3;
	por2.Show();

	Port por3(por1);
	por3 += 4;
	cout << por3;
	cout << endl;

	VintagePort vin1("ÕÅÈý", 30, "wangwu", "zhaoliu", 80);
	vin1.Show();

	VintagePort vin2;
	vin2 = vin1;
	vin2 -= 3;
	vin2.Show();

	VintagePort vin3(vin1);
	vin3 += 4;
	cout << vin3;


	system("pause");
	return 0;
}