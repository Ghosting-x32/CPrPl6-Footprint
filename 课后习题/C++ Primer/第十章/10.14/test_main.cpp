#include<iostream>
#include<vector>
#include<string>
#include<iterator>
#include<cstddef>
#include<algorithm>
#include<numeric>
#include<list>
#include<fstream>









using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::vector;
using std::string;
using std::begin;
using std::end;
using std::size_t;
using std::count;
using std::list;










int main()
{
	auto func = [](int a, int b)
		{
			return a + b;
		};

	auto aa = func(20, 30);

	cout << aa << endl;




	cout << endl;
	system("pause");
	return 0;
}


