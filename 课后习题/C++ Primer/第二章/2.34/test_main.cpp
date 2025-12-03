#include<iostream>




int main()
{
	int i = 0, & r = i;
	auto a = r;
	std::cout << a << std::endl;
	a = 42;
	std::cout << a << std::endl;

	const int ci = i, & cr = ci;
	auto b = ci;//auto推断会忽略顶层const
	std::cout << b << std::endl;
	b = 42;
	std::cout << b << std::endl;

	auto c = cr;
	std::cout << c << std::endl;
	c = 42;
	std::cout << c << std::endl;


	auto d = &i;
	std::cout << d << std::endl;
	//d = 42;//d的类型就是int*，不能用字面值数值给整型指针赋值
	//std::cout << d << std::endl;

	auto e = &ci;
	std::cout << e << std::endl;
	//e = 42;//e的类型就是const int*,不能用字面值数值给指向整型常量的指针赋值
	//std::cout << e << std::endl;


	auto& g = ci;
	std::cout << g << std::endl;
	//g = 42;//g的类型就是const int&,不能通过常量引用修改对应对象的值
	//std::cout << g << std::endl;


	system("pause");
	return 0;
}