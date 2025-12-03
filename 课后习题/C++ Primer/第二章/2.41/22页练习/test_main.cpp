#include<iostream>
#include<string>
#include"Sales_data.h"



int main()
{

	Sales_data data1, data2;
	


	double price = 0;
	std::cin >> data1.bookNo >> data1.units_sold >> price;
	data1.revenue = data1.units_sold * price;

	
	while (std::cin >> data2.bookNo && data2.bookNo != "q")//输入"q"结束循环(CTRL + Z模拟文件尾结束循环)
	{
			
		 std::cin >> data2.units_sold >> price;
		data2.revenue = data2.units_sold * price;

		if (data1.bookNo == data2.bookNo)
		{
			data1.revenue += data2.revenue;
			data1.units_sold += data2.units_sold;
		}
		else
		{
			std::cout << data1.bookNo << " " << data1.units_sold  << " " << data1.revenue << " " << data1.revenue / data1.units_sold << std::endl;


			data1.bookNo = data2.bookNo;
			data1.revenue = data2.revenue;
			data1.units_sold = data2.units_sold;
		}


	}

	std::cout << data1.bookNo << " " << data1.units_sold << " " << data1.revenue << " " << data1.revenue / data1.units_sold << std::endl;



	system("pause");
	return 0;
}