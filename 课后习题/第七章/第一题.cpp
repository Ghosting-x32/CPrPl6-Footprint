#include<iostream>
double f1(double x, double y);

int main()
{
	using namespace std;
	double x1;
	double y1;
	double thpjs;
	cout << "请输入你的两个数：";
	while (cin >> x1 >> y1 && x1 != 0 && y1 != 0)
	{
		thpjs = f1(x1, y1);
		cout << "这两个数的调和平均数是：";
		cout << thpjs << endl;
		cout << "请输入你的两个数：";
	}

	cout << endl;
	system("pause");
	return 0;
}

double f1(double x, double y)
{
	double jg = 2.0 * x * y / (x + y);
	return jg;
}
