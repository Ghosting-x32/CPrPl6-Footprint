#include<iostream>
#include<string>
#include<cmath>

#include"bad_gmean.h"
#include"bad_hmean.h"

using namespace std;

double hmean(double a, double b);
double gmean(double a, double b);



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
			cout << "Harmonic mean of " << x << " and " << y << " is " << z << endl;

			cout << "Geometric mean of " << x << " and " << y << " is " << gmean(x, y) << endl;

			cout << "请输入任意字符开始测试！ q代表退出: " << endl;
		}

		//catch (bad_gmean& hg)//catch块2，异常处理程序2
		//{
		//	hg.mesg();
		//	cout << hg.what();//第3题测试代码			
		//	cout << "Sorry, you don't get to play any more.\n";
		//	break;
		//}

		catch (bad_hmean& bg)//catch块1，异常处理程序1
		{//第3题测试代码---父类异常类型可以捕获子类异常
			bg.mesg();
			cout << bg.what();
			cout << "Sorry, you don't get to play any more.\n";
			//cout << "请输入任意字符开始测试！ q代表退出\nTry again.\n";
			break;
		}

		
		


	}



	system("pause");
	return 0;
}


double hmean(double a, double b)
{
	if (a == -b)
	{
		throw bad_hmean(a, b);//抛出异常,异常的类型为bad_hmean---抛出一个bad_hmean类的匿名对象
	}
	return 2.0 * a * b / (a + b);//两个数的调和平均数


}

double gmean(double a, double b)
{
	if (a < 0 || b < 0)
	{
		throw bad_gmean(a, b);//抛出异常,异常的类型为bad_gmean---抛出一个bad_gmean类的匿名对象

	}

	return sqrt(a * b);//两个数的几何平均值
}