#include<iostream>
#include<vector>
#include<string>
#include<iterator>
#include<cstddef>
#include<cctype>
#include<initializer_list>
#include<cstdlib>

#include"Sales_data.h"





using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::begin;
using std::end;
using std::size_t;
using std::isupper;
using std::tolower;
using std::initializer_list;










int main()
{
	Sales_data data1, data2;



	double price = 0;
	cin >> data1.bookNo >> data1.units_sold >> price;
	data1.revenue = data1.units_sold * price;


	while (cin >> data2.bookNo && data2.bookNo != "q")//输入"q"结束循环(CTRL + Z模拟文件尾结束循环)
	{

		cin >> data2.units_sold >> price;
		data2.revenue = data2.units_sold * price;

		if (data1.bookNo == data2.bookNo)
		{
			data1.revenue += data2.revenue;
			data1.units_sold += data2.units_sold;
		}
		else
		{
			cout << data1.bookNo << " " << data1.units_sold << " " << data1.revenue << " " << data1.revenue / data1.units_sold << endl;


			data1.bookNo = data2.bookNo;
			data1.revenue = data2.revenue;
			data1.units_sold = data2.units_sold;
		}


	}

	cout << data1.bookNo << " " << data1.units_sold << " " << data1.revenue << " " << data1.revenue / data1.units_sold << endl;

	
	

	system("pause");
	return 0;
}








