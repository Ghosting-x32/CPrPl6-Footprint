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
	cout << "通过类对象调用static成员" << endl;
	Son s1;
	cout << "子类里面的static成员m_A = " << s1.m_A << endl;
	cout << "父类里面的static成员m_A = " << s1.Base::m_A << endl << endl;

	cout << "通过类名调用static成员" << endl;
	cout << "子类里面的static成员m_A = " << Son::m_A << endl;
	cout << "父类里面的static成员m_A = " << Son::Base::m_A << endl << endl;
}

void test02()
{
	cout << "通过类对象调用static成员函数" << endl;
	Son s2;
	s2.func();//子类里面的static func（）函数调用
	s2.Base::func();//父类里面的static func（）函数调用
	s2.Base::func(3);//父类里面的static func（int a）函数调用----父类里面的成员函数重载
	cout << endl;

	cout << "通过类名调用static成员函数" << endl;
	Son::func();
	Son::Base::func();
	Son::Base::func(10);
	cout << endl;
}
