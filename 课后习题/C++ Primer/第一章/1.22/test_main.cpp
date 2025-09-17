#include<iostream>
#include<string>
#include"Sales_item.h"

int main()
{
	
	Sales_item total, trans;
	
	std::string index = " ";
	std::cout << "请输入任意键开始，输入\"退出\"代表退出程序" << std::endl;
	while (index != "退出")
	{
		std::cin >> index;
		std::cout << "请输入几条ISBN 相同的销售记录："
			<< std::endl;
		std::cin.clear();//上面的代码cin读取失败，从而设置位，预先重置位，让cin能正常继续读取


		while (std::cin.get() != '\n')
		{
			continue;
		}


		if (std::cin >> total)
		{
			while (std::cin >> trans)
			{
				if (compareIsbn(total, trans)) // ISBN 相同
				{
					total += trans;
					
				}
				else
				{ // ISBN 不同
					std::cout << "ISBN 不同" << std::endl;
					break;
				}
				
			}
			std::cout << "汇总信息：ISBN、售出本数、销售额和平均售价为 "
				<< total << std::endl;

		}
		else
		{
			std::cout << "你还没有输入任何数据" << std::endl;

		}

		std::cin.clear();//cin输入失败会返回false，并设置位，不能继续使用cin进行读取，需要继续读取则必须重置位，使用cin.clear()

		while (std::cin.get() != '\n')
		{
			continue;
		}
		std::cout << "请输入任意键开始，输入\"退出\"代表退出程序" << std::endl;
	}
	

	system("pause");
	return 0;
}