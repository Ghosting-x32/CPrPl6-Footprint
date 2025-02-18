#include<iostream>
#include"biaotou.h"
using namespace std;
using namespace SALES;

int main()
{
	Sales ann, cnn;
	setSales(ann);
	double hha[QUARTERS] = { 3.2, 4.8, 6.9, 8.8 };
	setSales(cnn, hha, QUARTERS);
	showSales(ann);
	showSales(cnn);



	system("pause");
	return 0;
}
