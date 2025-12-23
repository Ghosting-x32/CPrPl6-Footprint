#include<iostream>
#include<vector>
#include<string>
#include<iterator>
#include<cstddef>






using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::begin;
using std::end;
using std::size_t;



void chenge(int& p1, int& p2);




int main()
{

	/*
	
	与使用指针相比，使用引用交换变量的内容从形式上看更简单一些，并且无须
额外声明指针变量，也避免了拷贝指针的值
	
	*/
	int a = 2, b = 20;


	cout << "交换前 a = " << a << "\tb = " << b << endl;


	chenge(a, b);

	cout << "交换后 a = " << a << "\tb = " << b << endl;
	//cout << a << " " << b << endl;





	system("pause");
	return 0;
}


void chenge(int& p1, int& p2)
{
	int temp = 0;
	temp = p1;
	p1 = p2;
	p2 = temp;

}

