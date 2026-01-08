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
	vector<int> v1;
	deque<int> v2;
	deque<int> v3;
	deque<int> v4;

	for (vector<int>::size_type i = 1; i < 10; ++i)
	{
		v1.push_back(i);
	}

	for (const auto& c : v1)
	{
		cout << c << " ";
	}
	cout << endl;

	std::copy(v1.begin(), v1.end(), std::front_inserter(v2));
	cout << "front_inserter的插入效果:" << endl;
	for (const auto& c : v2)
	{
		cout << c << " ";
	}
	cout << endl;


	std::copy(v1.begin(), v1.end(), std::back_inserter(v3));
	cout << "back_inserter的插入效果:" << endl;
	for (const auto& c : v3)
	{
		cout << c << " ";
	}
	cout << endl;



	std::copy(v1.begin(), v1.end(), std::inserter(v4, v4.begin()));
	cout << "inserter的插入效果:" << endl;

	for (const auto& c : v4)
	{
		cout << c << " ";
	}
	cout << endl;








	cout << endl;
	system("pause");
	return 0;
}


