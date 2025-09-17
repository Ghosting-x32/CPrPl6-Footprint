#include<iostream>

int main()
{

	int val1 = 0, val2 = 0;
	std::cout << "请输入两个整数: " << std::endl;
	std::cin >> val1 >> val2;

	std::cout << val1 << "-" << val2 <<  "之间的整数分别为: ";

	if (val1 > val2)
	{
		while (val1 >= val2)
		{
			std::cout << val1 << " ";
			--val1;
		}
		std::cout << std::endl;
	}
	else if (val1 < val2)
	{
		while (val2 >= val1)
		{
			std::cout << val2 << " ";
			--val2;
		}
		std::cout << std::endl;
	}
	else
	{
		std::cout << val1 << std::endl;
	}


	




	system("pause");
	return 0;
}