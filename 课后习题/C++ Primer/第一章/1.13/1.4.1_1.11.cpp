#include<iostream>

int main()
{

	
	int val1 = 0, val2 = 0;
	std::cout << "��������������: " << std::endl;
	std::cin >> val1 >> val2;

	std::cout << val1 << "-" << val2 << "֮��������ֱ�Ϊ: ";

	if (val1 > val2)
	{

		for (int i = val1; i >= val2; --i)
		{
			std::cout << i << " ";
		}
		std::cout << std::endl;


	}
	else if (val1 < val2)
	{
		for (int i = val2; i >= val1; --i)
		{
			std::cout << i << " ";
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