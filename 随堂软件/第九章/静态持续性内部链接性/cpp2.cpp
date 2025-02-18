#include<iostream>
#include"biaotou.h"
int tom = 3;
int dick = 30;
static int harry = 300;

int main()
{
	using namespace std;
	cout << "main() reports the following addresses:\n";
	cout << &tom << " = &tom, " << &dick << " = &dick, ";
	cout << &harry << " = &harry\n";
	remote_access();


	system("pause");
	return 0;
}