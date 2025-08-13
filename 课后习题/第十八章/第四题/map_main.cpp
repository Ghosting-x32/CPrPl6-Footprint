#include<iostream>
#include<string>
#include<list>
#include<algorithm>

//#include"TooBig.h"

using namespace std;

//void outint(int n);

int main()
{
	//TooBig<int> f100(100);//仿函数模板实例化

	auto outint_lmd = [](int n) {cout << n << " "; };//有名称的lambda


	int vals[10] = { 50, 100, 90, 180, 60, 210, 415, 88, 188, 201 };
	list<int> yadayada(vals, vals + 10);
	list<int> etcetera(vals, vals + 10);

	cout << "Original lists:\n";
	for_each(yadayada.begin(), yadayada.end(), outint_lmd);
	//for_each(yadayada.begin(), yadayada.end(), outint);
	cout << endl;
	for_each(etcetera.begin(), etcetera.end(), outint_lmd);
	//for_each(etcetera.begin(), etcetera.end(), outint);
	cout << endl;

	//yadayada.remove_if(f100);//移除链表中大于100的数
	yadayada.remove_if([](int n) {return n > 100; });
	//etcetera.remove_if(TooBig<int>(200));//匿名函数对象，匿名谓词做函数的处理方法
	etcetera.remove_if([](int n) {return n > 200; });

	cout << "Trimmed lists:\n";
	for_each(yadayada.begin(), yadayada.end(), outint_lmd);
	//for_each(yadayada.begin(), yadayada.end(), outint);
	cout << endl;
	for_each(etcetera.begin(), etcetera.end(), outint_lmd);
	//for_each(etcetera.begin(), etcetera.end(), outint);
	cout << endl;






	system("pause");
	return 0;
}


//void outint(int n)
//{
//	cout << n << " ";
//
//}