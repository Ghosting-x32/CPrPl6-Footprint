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
	int aa_aa = 3;


	auto func = [aa_aa](int a)
		{
			return aa_aa + a;
		};

	auto aa = func(20);

	cout << aa << endl;




	cout << endl;
	system("pause");
	return 0;
}


