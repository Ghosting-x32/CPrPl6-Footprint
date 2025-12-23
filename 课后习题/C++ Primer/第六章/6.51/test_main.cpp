#include<iostream>
#include<vector>
#include<string>
#include<iterator>
#include<cstddef>
#include<cctype>
#include<initializer_list>
#include<cstdlib>//return EXIT_SUCCESS;预处理变量不需要std::(using namdespace std;)







using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::begin;
using std::end;
using std::size_t;
using std::isupper;
using std::tolower;
using std::initializer_list;




void f();
void f(int val);
void f(int val1, int val2);//#1
void f(double val1, double val2 = 3.14);//#2








int main()
{
	
	//f(2.56, 42);//有二义性报错#1和#2没有孰优孰劣之分
	f(42);
	f(42, 0);
	f(2.56, 3.14);



	

	system("pause");
	return 0;

}

void f()
{
	cout << "这里是走void f()函数！！！" << endl;

}


void f(int val)
{

	cout << "这里是走void f(int val)函数！！！" << endl;
}


void f(int val1, int val2)
{

	cout << "这里是走void f(int val1, int val2)函数！！！" << endl;
}


void f(double val1, double val2)
{
	cout << "这里是走void f(double val1, double val2)函数！！！" << endl;

}






