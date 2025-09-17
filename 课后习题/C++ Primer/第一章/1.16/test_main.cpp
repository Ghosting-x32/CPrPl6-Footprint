#include<iostream>

int main()
{

	int sum = 0, value = 0;
	std::cout << "请输入一组整数:(按Ctrl+Z 表示结束)" << std::endl;
	while (std::cin >> value)
	{
		sum += value;
	}
	std::cout << "Sum is: " << sum << std::endl;



	system("pause"); 
	return 0;
}