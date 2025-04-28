#include<iostream>
#include<string>
#include<cstdlib>
#include <stdexcept>// 新增头文件
#include <exception> // 新增头文件

using namespace std;

double hmean(double a, double b);
// 全局终止处理函数
void customTerminate() {
	cerr << "abnormal program termination\n";
	exit(EXIT_FAILURE);
}

int main()
{
	set_terminate(customTerminate); // 设置自定义终止处理

	double x, y, z;	
	char ch;
	cout << "请输入任意字符开始测试！ q代表退出" << endl;
	while (cin >> ch && ch != 'q')
	{
		while (cin.get() != '\n')
		{
			continue;
		}
		cout << "Enter two numbers: ";
		while (!(cin >> x >> y))
		{
			cin.clear();
			while (cin.get() != '\n')
			{
				continue;
			}
			cout << "Incorrect input, please enter a number!" << endl;
		}

		while (cin.get() != '\n')
		{
			continue;
		}

		z = hmean(x, y);
		cout << "Harmonic mean of " << x << " and " << y << " is " << z << endl;
		cout << "Enter next set of numbers <q to quit>: ";


	}
	


	system("pause");
	return 0;
}


double hmean(double a, double b)
{

	if (a == -b)
	{
		cout << "untenable arguments to hmean()\n";
		terminate(); // 触发自定义终止处理
		//abort();//向标准错误流（cerr）发送消息abnormal program termination（程序异常终止），然后终止程序
	}
	return 2.0 * a * b / (a + b);



}