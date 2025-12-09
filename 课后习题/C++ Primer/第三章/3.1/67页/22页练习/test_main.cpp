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

	if (cin >> data1.bookNo && cin >> data1.units_sold && cin >> price)
	{
		data1.revenue = data1.units_sold * price;


		while (cin >> data2.bookNo && cin >> data2.units_sold && cin >> price)//(CTRL + Z模拟文件尾结束循环)
		{
		
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



	}
	else
	{
		cout << "你还没有输入任何销售记录!" << endl;
	}
	 
	

	system("pause");
	return 0;
}