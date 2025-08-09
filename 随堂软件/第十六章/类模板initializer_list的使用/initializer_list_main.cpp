#include<iostream>
#include<string>
#include<initializer_list>

using namespace std;

double sum(initializer_list<double> il);//初始化列表可按值传递也可按引用传递
double average(const initializer_list<double>& ril);

int main()
{
	//cout << "List 1: sum = " << sum({ 2, 3, 4 }) << ", ave = " << average({ 2, 3, 4 }) << "\n";//等效于下面的语句
	cout << "List 1: sum = " << sum(initializer_list<double>{ 2, 3, 4 }) << ", ave = " << average(initializer_list<double>{ 2, 3, 4 }) << "\n";
	//匿名的initializer_list<double>类对象{ 2, 3, 4 }

	//initializer_list<double> d1 = { 1.1, 2.2, 3.3, 4.4, 5.5 };
	//initializer_list<double> d1{ 1.1, 2.2, 3.3, 4.4, 5.5 };//初始化列表{}可代替(),也可以这样({})
	initializer_list<double> d1({ 1.1, 2.2, 3.3, 4.4, 5.5 });//初始化列表{}可代替(),也可以这样({})
	cout << "List 2: sum = " << sum(d1) << ", ave = " << average(d1) << "\n";

	d1 = { 16.0, 25.0, 36.0, 40.0, 64.0 };
	//匿名的initializer_list<double>类对象{ 16.0, 25.0, 36.0, 40.0, 64.0 }
	cout << "List 3: sum = " << sum(d1) << ", ave = " << average(d1) << "\n";






	system("pause");
	return 0;
}



double sum(initializer_list<double> il)
{
	double tot = 0;
	for (auto p = il.begin(); p != il.end(); p++)
	{
		tot += *p;

	}

	return tot;


}


double average(const initializer_list<double>& ril)
{
	double tot = 0;
	int n = ril.size();
	double ave = 0.0;
	if (n > 0)
	{
		for (auto p = ril.begin(); p != ril.end(); p++)
		{
			tot += *p;
		}
		ave = tot / n;

	}

	return ave;


}

