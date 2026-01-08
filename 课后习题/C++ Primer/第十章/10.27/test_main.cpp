#include<iostream>
#include<vector>
#include<string>
#include<iterator>
#include<cstddef>
#include<algorithm>
#include<numeric>
#include<functional>
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
	vector<string> v1{ "aaa", "bbb", "ccc", "ddd", "aaa", "bbb", "ddd" };
	list<string> v2;

	for (const auto& c : v1)
	{
		cout << c << " ";
	}
	cout << endl;

	std::stable_sort(v1.begin(), v1.end());
	for (const auto& c : v1)
	{
		cout << c << " ";
	}
	cout << endl;


	auto it = std::front_inserter(v2);
	//std::front_insert_iterator it = std::front_inserter(v2);

	std::unique_copy(v1.begin(), v1.end(), it);

	for (const auto& c : v1)
	{
		cout << c << " ";
	}
	cout << endl;


	cout << v2.size() << endl;
	for (const auto& c : v2)
	{
		cout << c << " ";
	}
	cout << endl;


	cout << endl;
	system("pause");
	return 0;
}


