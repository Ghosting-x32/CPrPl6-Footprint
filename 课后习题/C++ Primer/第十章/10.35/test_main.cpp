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
	vector<int> v1 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };

	auto it = v1.end();
	while (it != v1.begin())
	{
		cout << *(--it) << " ";					
	}


	cout << endl;
	system("pause");
	return 0;
}


