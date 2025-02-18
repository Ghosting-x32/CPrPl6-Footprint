#include<iostream>
#include"sales.h"


int main()
{
	using namespace std;
	using namespace SALES;
	const int CL = 4;
	double cssz[CL] = { 12.3, 36.2, 56.2, 69.2 };
	Sales one = Sales(cssz, 4);
	one.Show();
	Sales two;
	two.setSales();
	two.Show();

	system("pause");
	return 0;
}
