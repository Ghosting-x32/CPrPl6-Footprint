#include<iostream>
#include<string>
#include"Sales_data.h"

using std::cin;
using std::cout;
using std::endl;



int main()
{
	Sales_data data1;
	double price = 0;
	cin >> data1.bookNo >> data1.units_sold >> price;
	data1.revenue = data1.units_sold * price;

	cout << data1.bookNo << " " << data1.units_sold << " "
		<< data1.revenue << " " << data1.revenue / data1.units_sold << endl;





	system("pause");
	return 0;
}