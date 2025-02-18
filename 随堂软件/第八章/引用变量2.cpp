#include<iostream>


int main()
{
	using namespace std;
	int rats = 101;
	int& rodents = rats;
	cout << "rats = " << rats;
	cout << ", rodents = " << rodents << endl;
	cout << "rats adddress = " << &rats;
	cout << ", rodents address = " << &rodents << endl;
	int bunnies = 50;
	rodents = bunnies;
	cout << "bunnies = " << bunnies;
	cout << ", rats = " << rats;
	cout << ", rodents = " << rodents << endl;
	cout << "bunnies address = " << &bunnies;
	cout << ", rodentd adress = " << &rodents << endl;




	system("pause");
	return 0;
}


