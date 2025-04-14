#include<iostream>
#include<string>
#include"Base.h"
#include"Son.h"
#include"Son1.h"
#include"Son2.h"
using namespace std;
void test01();



int main()
{
	test01();


	system("pause");
	return 0;
}

void test01()
{
	Son son;
	son.m_A = 20;//公有继承时，父类中的public（公有属性）成员到子类还是公有属性----类内可以访问，类外也可访问
	//son.m_B = 20;//公有继承时，父类中的protected（保护属性）成员到子类还是保护属性----类内可以访问，类外不可访问

	Son1 son1;
	//son1.m_A = 20; //保护继承时，父类中的public（公有属性）成员到子类变成protected（保护属性）----类内可以访问，类外不可访问
	//son1.m_B = 20;//保护继承时，父类中的protected（保护属性）成员到子类还是保护属性----类内可以访问，类外不可访问

	Son2 son2;
	//son2.m_A = 20;//私有继承时，父类中的public(共有属性)成员函数到子类变成privat(私有属性）----类内可以访问，类外不可访问
	//son2.m_A = 20;//私有继承时，父类中的protected(保护属性)成员函数到子类变成privat(私有属性）----类内可以访问，类外不可访问
}

