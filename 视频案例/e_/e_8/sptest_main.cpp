#include<iostream>
#include<string>
#include"Computer.h"


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
	Computer<string, int>p1("张三", 63);
	p1.ShowComputer();

}



