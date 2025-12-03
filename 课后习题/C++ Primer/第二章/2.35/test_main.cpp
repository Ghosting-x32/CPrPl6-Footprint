#include<iostream>
#include<typeinfo>



int main()
{

	/*
由题意可知，i 是一个整型常量，j 的类型推断结果是整数，k 的类型推断结果
是整型常量，p 的类型推断结果是指向整型常量的指针，j2 的类型推断结果是整数，
k2 的类型推断结果是整数。
		
	*/
	const int i = 42;//i:const int
	auto j = i;//j:int
	const auto& k = i;//k:const int&
	auto* p = &i;//p:const int*
	const auto j2 = i, & k2 = i;//j2:const int    k2:const int&
	
	std::cout << typeid(i).name() << std::endl;
	std::cout << typeid(j).name() << std::endl;
	std::cout << typeid(k).name() << std::endl;
	std::cout << typeid(p).name() << std::endl;
	std::cout << typeid(j2).name() << std::endl;
	std::cout << typeid(k2).name() << std::endl;


	system("pause");
	return 0;
}