#include <iostream>
#include<array>
//#include"Adder.h"

using namespace std;

const int Size = 5;

template<typename T>
void sum(array<double, Size> a, T fp);//使用lambda表达式需要把sum的第二个参数改为按值传递


int main()
{
	double total = 0.0;
	//Adder ad(total);
	array<double, Size> temp_c = { 32.1, 34.3, 37.8, 35.2, 34.7 };
	sum(temp_c, [&total](double w) {total += w; });//lambda表达式可在中括号中使用作用域内的变量的引用，使其改变该变量
	//total = ad.tot_v();
	//cout << "total: " << ad.tot_v() << "\n";
	cout << "total: " << total << "\n";

	system("pause");
	return 0;
}

template<typename T>
void sum(array<double, Size>a, T fp)
{
	for (auto pt = a.begin(); pt != a.end(); ++pt)
	{

		fp(*pt);
	}

}
