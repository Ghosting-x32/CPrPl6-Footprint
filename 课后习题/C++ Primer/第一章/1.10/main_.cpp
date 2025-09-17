#include<iostream>

int main()
{

	int val = 10;
	std::cout << "10-0之间的整数分别为: ";
	while (val >= 0)
	{	
		std::cout << val << " ";
		--val;
	}
	std::cout << std::endl;




	system("pause");
	return 0;
}