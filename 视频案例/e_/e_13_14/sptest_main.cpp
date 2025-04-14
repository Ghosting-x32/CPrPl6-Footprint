#include<iostream>
#include<string>
#include"Computer.hpp"

//模板类作为函数形参
using namespace std;
void printComputer(Computer<string, int>& p);

template<typename T3,typename T4>
void printComputer1(Computer<T3, T4>& p)//2.参数模板化--函数模板与类模板结合（函数模板能自动推断类型）
{
	p.ShowComputer();
	cout << "T3的类型为：" << typeid(T3).name() << endl;//查看模板的类型
	cout << "T4的类型为：" << typeid(T4).name() << endl;
}

template<typename T>
void printComputer2(T& p)//3.整个类模板化--函数模板与类模板结合（函数模板能自动推断类型）
{
	p.ShowComputer();
	cout << "T的类型为：" << typeid(T).name() << endl;//查看模板的类型
}

void test01();




int main()
{
	test01();


	system("pause");
	return 0;
}


void printComputer(Computer<string, int>& p)//1.指定传入类型
{
	p.ShowComputer();
}

void test01()
{
	Computer<string, int>p("孙悟空", 999);
	printComputer(p);
	cout << "--------------------" << endl;

	Computer<string, int>p1("猪八戒", 1000);
	printComputer1(p1);
	cout << "--------------------" << endl;

	Computer<string, int>p2("唐僧", 30);
	printComputer2(p2);
}



