#include<iostream>
#include<string>
#include"Base.h"
#include"Son.h"
using namespace std;
void test01();
void test02();



int main()
{
	test01();
	test02();

	system("pause");
	return 0;
}

void test01()
{
	Son s1;
	cout << "子类里面的成员m_A = " << s1.m_A << endl;
	cout << "父类里面的成员m_A = " << s1.Base::m_A << endl;
}

void test02()
{
	Son s2;
	s2.func();//子类里面的func（）函数调用
	s2.Base::func();//父类里面的func（）函数调用
	s2.Base::func(3);//父类里面的func（int a）函数调用----父类里面的成员函数重载
}
