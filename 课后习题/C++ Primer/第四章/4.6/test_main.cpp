#include<iostream>
#include<vector>
#include<string>
#include<cctype>
#include<iterator>
#include<cstddef>
#include<typeinfo>
#include<cstring>                  




using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::begin;
using std::end;
using std::size_t;
using std::ptrdiff_t;
using std::strlen;




int main()
{
	/*
	下面的表达式可以用于确定一个整数是奇数还是偶数，假设该整数名为num，
	则表达式num % 2 == 0 为真时num 是偶数，该表达式为假时num 是奇数。
	*/

	int num = 0;
	cin >> num;
	if (num % 2 == 0)
	{
		cout << "num是一个偶数" << endl;
	}
	else
	{
		cout << "num是一个奇数" << endl;
	}






	system("pause");
	return 0;
}