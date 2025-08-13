#include<iostream>
#include"Useless.h"

using namespace std;



int main()
{
	{
		Useless one(10, 'x');
		Useless two = one + one;//原则上是使用移动复制构造函数（存在RVO）
		cout << "object one: ";
		one.ShowData();
		cout << "object two: ";
		two.ShowData();

		Useless three, four;
		cout << "three = one\n";
		three = one;//使用常规赋值运算符
		cout << "now object three = ";
		three.ShowData();
		cout << "and object one = ";
		one.ShowData();

		cout << "four = one + two\n";
		four = one + two;//使用移动赋值运算符
		cout << "now object four = ";
		four.ShowData();

		cout << "four = move(one)\n";
		four = move(one);//强制使用移动赋值运算符
		cout << "now object four = ";
		four.ShowData();
		cout << "and object one = ";
		one.ShowData();


	
	
	}//代码块便于显示析构函数

	system("pause");
	return 0;
}