#include<iostream>
long double f1(int n);



int main()
{
	using namespace std;
	cout.setf(ios_base::fixed, ios_base::floatfield);
	int cs;
	long double csjc;
	cout << "请输入你需要计算的阶乘数：";
	while (cin >> cs)
	{
		csjc = f1(cs);
		cout << cs << " 的阶乘是：" << csjc << endl;
		cout << "请输入你需要计算的下一个阶乘数：";
	}
		


	system("pause");
	return 0;
}

long double f1(int n)
{
	long double jc = 1;
	if (n > 0) 
		jc = n * f1(n - 1);	
	return jc;
}
