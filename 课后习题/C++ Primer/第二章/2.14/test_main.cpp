#include<iostream>




int i = 200;

int main()
{
	
	int i = 100, sum1 = 0, sum2 = 0, sum3 = 0;
	int j = i;

	for (int i = 0; i != 10; ++i)
	{
		sum1 += ::i;
		sum2 += i;
		sum3 += j;
		//嵌套作用域
		//要在内层作用域内访问外层作用域下同名的变量，除非外层作用域是全局作用域，否则，没有办法在内层作用域内访问外层作用域下同名的变量
		//例如：要访问外层作用域值为100的i，除非i声明定义在main函数之外的全局作用域下，否则没有办法在这里访问值为100的i
		//sum += ::i;i声明定义在main函数之外的全局作用域下的话可以这样访问
	}
	std::cout << ::i << " " << sum1 << std::endl;
	std::cout << i << " " << sum2 << std::endl;
	std::cout << i << " " << sum3 << std::endl;


	system("pause");
	return 0;
}