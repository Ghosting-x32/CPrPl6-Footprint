#include<iostream>
#include<string>

using namespace std;

double hmean(double a, double b);


int main()
{


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


		try//try块
		{
			z = hmean(x, y);
		}

		catch (const char* s)//catch块，异常处理程序
		{
			cout << s << endl;
			cout << "请输入任意字符开始测试！ q代表退出\nEnter a new pair of numbers: ";
			continue;
		}

		cout << "Harmonic mean of " << x << " and " << y << " is " << z << endl;
		cout << "请输入任意字符开始测试！ q代表退出: ";


	}



	system("pause");
	return 0;
}


double hmean(double a, double b)
{
	if (a == -b)
	{
		throw "bad hmean() arguments: a = -b not allowed\n你的输入导致分母为0，请重新输入！";//抛出异常
	}
	return 2.0 * a * b / (a + b);


}