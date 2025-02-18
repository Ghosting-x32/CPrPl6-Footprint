#include<iostream>
#include"biaotou.h"
using namespace std;

namespace SALES
{
	void setSales(Sales& s, const double ar[], int n)
	{
		for (int i = 0; i < n; i++)
			s.sales[i] = ar[i];
	}

	void setSales(Sales& s)
	{
		cout << "请输入数组内容：" << endl;
		for (int i = 0; i < QUARTERS; i++)
			cin >> s.sales[i];
	}

	void showSales(const Sales& s)
	{
		cout << "数组内容是：";
		for (int i = 0; i < QUARTERS; i++)
			cout << s.sales[i] << " ";

		double total = 0;
		for (int i = 0; i < QUARTERS; i++)
			total += s.sales[i];
		cout << endl << "average: " << total / QUARTERS << endl;

		double mc = s.sales[0];
		for (int i = 0; i < QUARTERS; i++)
		{
			mc = mc > s.sales[i + 1] ? mc : s.sales[i + 1];
		}
		cout << "max: " << mc << endl;

		double ma = s.sales[0];
		for (int i = 1; i < QUARTERS; i++)
		{
			ma = ma < s.sales[i] ? ma : s.sales[i];
		}
		cout << "min: " << ma << endl;
	}
}
