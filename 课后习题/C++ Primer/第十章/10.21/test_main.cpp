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
	int a = 10;






	auto func = [&a]() -> bool
		{
			if (a != 0)
			{
				--a;
			}

			return a == 0 ? true : false;
		};

	for (size_t i = 0; i < 12; ++i)
	{
		auto temp = func();
		cout << temp << "\t" << a << endl;

	}





	cout << endl;
	system("pause");
	return 0;
}


