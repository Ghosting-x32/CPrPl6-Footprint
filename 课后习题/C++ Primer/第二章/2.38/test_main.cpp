#include<iostream>
#include<typeinfo>



int main()
{

	/*
auto 和decltype 的区别主要有三个方面：
第一，auto类型说明符用编译器计算变量的初始值来推断其类型，而decltype
虽然也让编译器分析表达式并得到它的类型，但是不实际计算表达式的值。
第二，编译器推断出来的auto 类型有时候和初始值的类型并不完全一样，编译
器会适当地改变结果类型使其更符合初始化规则。例如，auto 一般会忽略掉顶层
const，而把底层const 保留下来。与之相反，decltype 会保留变量的顶层const。
第三，与auto 不同，decltype 的结果类型与表达式形式密切相关，如果变量
名加上了一对括号，则得到的类型与不加括号时会有不同。如果decltype 使用的
是一个不加括号的变量，则得到的结果就是该变量的类型；如果给变量加上了一层
或多层括号，则编译器将推断得到引用类型。	
	*/



	int a = 3;
	auto c1 = a;//cl:int
	decltype(a) c2 = a;//c2:int
	decltype((a)) c3 = a;//c3:int&
	const int d = 5;
	auto f1 = d;//f1:int
	decltype(d) f2 = d;//f2:const int
	std::cout << typeid(c1).name() << std::endl;
	std::cout << typeid(c2).name() << std::endl;
	std::cout << typeid(c3).name() << std::endl;
	std::cout << typeid(f1).name() << std::endl;
	std::cout << typeid(f2).name() << std::endl;
	c1++;
	c2++;
	c3++;
	f1++;
//	f2++; // 错误：f2 是整型常量，不能执行自增操作
	std::cout << a << " " << c1 << " " << c2 << " " << c3 << " " << f1
		<< " " << f2 << std::endl;


	/*
	
	对于第一组类型推断来说，a 是一个非常量整数，c1 的推断结果是整数，c2 的
推断结果也是整数，c3 的推断结果由于变量a 额外加了一对括号所以是整数引用。
c1、c2、c3 依次执行自增操作，因为c3 是变量a 的别名，所以c3 自增等同于a
自增，最终a、c1、c2、c3 的值都变为4。
对于第二组类型推断来说，d 是一个常量整数，含有顶层const，使用auto
推断类型自动忽略掉顶层const，因此f1 的推断结果是整数；decltype 则保留
顶层const，所以f2 的推断结果是整数常量。f1 可以正常执行自增操作，而常量
f2 的值不能被改变，所以无法自增。
	
	*/


	system("pause");
	return 0;
}