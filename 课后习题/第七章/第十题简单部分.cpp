#include<iostream>
using namespace std;
double add(double x, double y);
double f1(double x1, double y1);
double f2(double x2, double y2);
double calculate(double a, double b, double (*pn)(double, double));


int main()
{
	double csx, csy;
	double jg1;
	double jg2;
	cout << "请输入两个需要计算的数字：(或者输入q结束）";
	while (cin >> csx >> csy)
	{
		jg1 = calculate(csx, csy, add);
		jg2 = calculate(csx, csy, f1);
		cout << "add计算的值jg1是：" << jg1 << endl;
		cout << "f1计算的值jg2是：" << jg2 << endl;
		cout << "请输入两个需要计算的数字：(或者输入q结束）";
	}





	system("pause");
	return 0;
}

double add(double x, double y)
{
	return x + y;
}

double f1(double x1, double y1)
{
	return x1 * y1;
}

double f2(double x2, double y2)
{
	return x2 / y2;
}

double calculate(double a, double b, double (*pn)(double, double))
{
	return (*pn)(a, b);
}