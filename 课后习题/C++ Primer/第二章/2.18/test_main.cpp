#include<iostream>




int main()
{

	int i = 5, j = 10;
	int* p = &i;
	std::cout << p << " " << *p << std::endl;
	p = &j;//改变指针的值
	std::cout << p << " " << *p << std::endl;
	*p = 20;//改变指针所指对象的值
	std::cout << p << " " << *p << std::endl;
	j = 30;//改变指针所指对象的值
	std::cout << p << " " << *p << std::endl;
/*
0x28fef8 5
0x28fef4 10
0x28fef4 20
0x28fef4 30

在上述示例中，首先定义了两个整型变量i 和j 以及一个整型指针p，初始情
况下令指针p 指向变量i，此时分别输出p 的值（即p 所指对象的内存地址）以及p
所指对象的值，得到0x28fef8 和5。
随后依次更改指针的值以及指针所指对象的值。p=&j;更改了指针的值，令指
针p 指向另外一个整数对象j。*p=20;和j=30是两种更改指针所指对象值的方式，
前者显式地更改指针p 所指的内容，后者则通过更改变量j 的值实现同样的目的。

*/
	

	system("pause");
	return 0;
}