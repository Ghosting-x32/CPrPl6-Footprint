#include<iostream>

int main()
{

	int sum = 0, value = 0;
	std::cout << "������һ������:(��Ctrl+Z ��ʾ����)" << std::endl;
	while (std::cin >> value)
	{
		sum += value;
	}
	std::cout << "Sum is: " << sum << std::endl;



	system("pause"); 
	return 0;
}