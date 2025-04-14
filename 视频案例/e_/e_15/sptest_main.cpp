#include<iostream>
#include<string>
#include"Computer.hpp"



void test01();




int main()
{
	test01();


	system("pause");
	return 0;
}


void test01()
{
	Computer<string, int>p("孙悟空", 999);
	ShowComputer(p);
	cout << "-----------------------" << endl;

	Computer<string, int>p1("猪八戒", 1000);
	ShowComputer1(p1);
}



