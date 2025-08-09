#include<iostream>
#include<string>
#include<cmath>


using namespace std;

int main()
{
	cout.setf(ios_base::left, ios_base::adjustfield);//左对齐
	cout.setf(ios_base::showpos);//显示+
	cout.setf(ios_base::showpoint);//显示小数点
	cout.precision(3);//默认状态精度---总位数
	//科学计数法和定点表示发状态下的精度是小数点后的位数

	ios_base::fmtflags old = cout.setf(ios_base::scientific, ios_base::floatfield);//科学计数法
	//储存以前的格式标签

	cout << "Left Justification:\n";
	long n;
	for (n = 1; n <= 41; n += 10)
	{
		cout.width(4);
		cout << n << "|";
		cout.width(12);
		cout << sqrt(double(n)) << "|\n";

	}


	cout.setf(ios_base::internal, ios_base::adjustfield);//符号或基数前缀左对齐，值右对齐
	cout.setf(old, ios_base::floatfield);//设置floatfield标签为以前的格式标签
	//以前的这一项的值是默认状态---既不是科学计数法也不是定点表示法

	//此时是默认状态精度---总位数3
	cout << "Internal Justification:\n";
	for (n = 1; n <= 41; n += 10)
	{
		cout.width(4);
		cout << n << "|";
		cout.width(12);
		cout << sqrt(double(n)) << "|\n";

	}

	cout.setf(ios_base::right, ios_base::adjustfield);//右对齐
	cout.setf(ios_base::fixed, ios_base::floatfield);//定点表示法
	cout << "Right Justification:\n";
	for (n = 1; n <= 41; n += 10)
	{
		cout.width(4);
		cout << n << "|";
		cout.width(12);
		cout << sqrt(double(n)) << "|\n";

	}











	system("pause");
	return 0;
}