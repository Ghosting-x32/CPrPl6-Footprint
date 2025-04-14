#include<iostream>
#include<string>
#include"BasePage.h"
#include"Java.h"
#include"Cpp.h"
#include"Python.h"
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
	Java j1;
	Python p1;
	Cpp c1;

	j1.header();
	j1.footer();
	j1.left();
	j1.content();
	cout << "---------------------------------------------------------" << endl;

	p1.header();
	p1.footer();
	p1.left();
	p1.content();
	cout << "---------------------------------------------------------" << endl;

	c1.header();
	c1.footer();
	c1.left();
	c1.content();
	cout << "---------------------------------------------------------" << endl;
}