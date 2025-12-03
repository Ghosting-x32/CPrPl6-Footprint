#include<iostream>
#include<string>
#include"Sales_data.h"



int main()
{

	Sales_data data1, data2;
	int sum = 1;


	double price = 0;
	std::cin >> data1.bookNo >> data1.units_sold >> price;
	data1.revenue = data1.units_sold * price;
	while (std::cin >> data2.bookNo && data2.bookNo != "q")//输入"q"结束循环
	{
			
		 std::cin >> data2.units_sold >> price;
		data2.revenue = data2.units_sold * price;

		if (data1.bookNo == data2.bookNo)
		{
			sum++;
		}
		else
		{
			std::cout << data1.bookNo << " 有 " << sum << " 条记录!" << std::endl;

			sum = 1;
		}

		data1.bookNo = data2.bookNo;
		data1.revenue = data2.revenue;
		data1.units_sold = data2.units_sold;



	}

	std::cout << data1.bookNo << " 有 " << sum << " 条记录!" << std::endl;



	system("pause");
	return 0;
}