#include<iostream>
#include"sales.h"

namespace SALES
{
	Sales::Sales()
	{
		sales[QUARTERS] = {0.0};
		average = 0.0;
		max = 0.0;
		min = 0.0;
	}

	Sales::Sales(const double ar[], int n)
	{
		for (int i = 0; i < n; i++)
		{
			this->sales[i] = ar[i];
		}
		double total = 0;
		for (int i = 0; i < n; i++)
			total += this->sales[i];
		average = total / n;
		double mc = this->sales[0];
		for (int i = 0; i < n; i++)
		{
			mc = mc > this->sales[i + 1] ? mc : this->sales[i + 1];
		}
		max = mc;
		double ma = this->sales[0];
		for (int i = 1; i < n; i++)
		{
			ma = ma < this->sales[i] ? ma : this->sales[i];
		}
		min = ma;
	}

	Sales::~Sales()
	{
	}

	void Sales::Show()const
	{
		using std::cout;
		using std::endl;
		cout << "类对象数组内容是：";
		for (int i = 0; i < QUARTERS; i++)
			cout << this->sales[i] << " ";
		cout << endl << "average: " << average << endl;
		cout << "max: " << max << endl;
		cout << "min: " << min << endl;
	}

	void Sales::setSales()
	{
		using std::cin;
		using std::endl;
		using std::cout;
		double linsz[QUARTERS];
		cout << "请输入类对象数组内容：" << endl;
		for (int i = 0; i < QUARTERS; i++)
		{
			cout << "第" << (i + 1) << "个值是：";
			cin >> linsz[i];
		}
		*this = Sales(linsz, QUARTERS);
	}
}