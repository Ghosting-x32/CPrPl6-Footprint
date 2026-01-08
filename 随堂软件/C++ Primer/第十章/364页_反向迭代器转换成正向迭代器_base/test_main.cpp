#include<iostream>
#include<vector>
#include<string>
#include<iterator>
#include<cstddef>
#include<algorithm>
#include<numeric>
#include<functional>
#include<list>
#include<deque>
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
using std::deque;









int main()
{
	string line("FIRST,MIDDLE,LAST");


	auto rcomma = std::find(line.crbegin(), line.crend(), ',');

	cout << string(rcomma.base(), line.cend()) << endl;





	cout << endl;
	system("pause");
	return 0;
}


