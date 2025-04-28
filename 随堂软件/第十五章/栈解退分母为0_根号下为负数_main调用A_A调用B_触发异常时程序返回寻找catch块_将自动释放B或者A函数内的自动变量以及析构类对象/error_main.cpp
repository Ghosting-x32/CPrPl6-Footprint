#include<iostream>
#include<string>
#include<cmath>

#include"bad_gmean.h"
#include"bad_hmean.h"
#include"demo.h"

using namespace std;

double hmean(double a, double b);
double gmean(double a, double b);
double means(double a, double b);



int main()
{


	double x, y, z;
	char ch;
	{
		demo d1("found in block in main()");
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
				z = means(x, y);
				cout << "The mean mean of " << x << " and " << y << " is " << z << endl;				

				cout << "请输入任意字符开始测试！ q代表退出: " << endl;
			}

			catch (bad_hmean& bg)//catch块1，异常处理程序1
			{
				bg.mesg();
				cout << "请输入任意字符开始测试！ q代表退出\nTry again.\n";
				continue;
			}

			catch (bad_gmean& hg)//catch块2，异常处理程序2
			{
				cout << hg.mesg();
				cout << "Values used: " << hg.v1 << ", " << hg.v2 << endl;
				cout << "Sorry, you don't get to play any more.\n";
				break;
			}



		}
		d1.show();
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


double means(double a, double b)
{
	double am, hm, gm;
	demo d2("found in means()");
	am = (a + b) / 2.0;//两个数的算术平均数
	try
	{
		hm = hmean(a, b);
		gm = gmean(a, b);//出现异常时，程序会回到main中寻找bad_gmean类型的catch块
		//gmean函数和means函数内的自动变量会释放，类对象会被析构---------栈解退

	}

	catch (bad_hmean& bg)//该函数中只写一个catch块，因此只能捕获bad_hmean类型的异常
	{
		bg.mesg();
		cout << "Caught in means()\n";
		throw;//处理异常继续抛出异常---异常传递

	}
	d2.show();
	return (am + hm + gm) / 3.0;//3种平均数在做平均值计算




}