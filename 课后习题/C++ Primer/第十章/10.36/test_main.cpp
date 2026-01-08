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

	list<int> v1{ 1, 2, 0, 3, 4, 0, 8, 9, 0, 7, 2 };


	auto it = std::find(v1.crbegin(), v1.crend(), 0);

	cout << *it << endl;
	cout << *(++it) << endl;
	//cout << *(--it) << endl;









	cout << endl;
	system("pause");
	return 0;
}


