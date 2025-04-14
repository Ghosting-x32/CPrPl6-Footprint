#include<iostream>
#include<string>


using namespace std;
void SwapInt(int& a, int& b);
void SwapDouble(double& a, double& b);
void test01();

template<typename T>
void MySwap(T& a, T& b)//函数模板的声明和定义必须在一起
{
	T temp = a;
	a = b;
	b = temp;
}



int main()
{
	test01();


	system("pause");
	return 0;
}



void test01()
{
	int a = 100;
	int b = 200;
	SwapInt(a, b);
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "-----------------------" << endl;

	MySwap(a, b);//自动类型推导
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "-----------------------" << endl;

	double c = 2.31;
	double f = 3.69;
	SwapDouble(c, f);
	cout << "c = " << c << endl;
	cout << "f = " << f << endl;
	cout << "-----------------------" << endl;

	MySwap<double>(c, f);//显示指定类型
	cout << "c = " << c << endl;
	cout << "f = " << f << endl;
}

void SwapInt(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

void SwapDouble(double& a, double& b)
{
	double temp = a;
	a = b;
	b = temp;
}

