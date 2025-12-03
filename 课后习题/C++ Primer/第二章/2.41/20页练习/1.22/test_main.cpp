#include<iostream>
#include<string>
#include"Sales_data.h"



int main()
{
	int jlts = 0;
	std::cout << "请输入需要读取的记录条数: " << std::endl;
	std::cin >> jlts;

	Sales_data data1;
	unsigned total_units_sold = 0;
	double total_revenue = 0;


	if (jlts > 0)
	{
		for (int i = 0; i < jlts; i++)
		{

			double price = 0;
			std::cin >> data1.bookNo >> data1.units_sold >> price;
			data1.revenue = data1.units_sold * price;

			total_units_sold += data1.units_sold;
			total_revenue += data1.revenue;

		}
		std::cout << data1.bookNo << " " << total_units_sold << " "
			<< total_revenue << " " << total_revenue / total_units_sold << std::endl;
	}
	else
	{
		std::cout << "没有任何销售记录！" << std::endl;
	}



	





	system("pause");
	return 0;
}