#include<iostream>
#include<string>
#include"Sales_data.h"

using std::cin;
using std::cout;
using std::endl;

int main()
{
	Sales_data data1, data2;
	double price = 0;
	cin >> data1.bookNo >> data1.units_sold >> price;
	data1.revenue = data1.units_sold * price;

	cin >> data2.bookNo >> data2.units_sold >> price;
	data2.revenue = data2.units_sold * price;

	unsigned total_units_sold = data1.units_sold + data2.units_sold;
	double total_revenue = data1.revenue + data2.revenue;

	cout << data1.bookNo << " " << total_units_sold << " "
		<< total_revenue << " " << total_revenue / total_units_sold << endl;





	system("pause");
	return 0;
}