#include<iostream>
#include<vector>
#include<string>
#include<iterator>
#include<cstddef>
#include<list>
#include<deque>




using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::vector;
using std::string;
using std::begin;
using std::end;
using std::size_t;
using std::list;
using std::deque;







int main()
{
	list<int> li_aa;
	deque<int> de_11;
	deque<int> de_22;
	for (size_t i = 0; i < 10; ++i)
	{
		li_aa.push_back(i);
	}
	for (auto it = li_aa.cbegin(); it != li_aa.cend(); ++it)
	{
		if (*it % 2 == 0)
		{
			de_22.push_back(*it);
		}
		else
		{
			de_11.push_back(*it);
		}
	}
	cout << "奇数：";
	for (const auto& c : de_11)
	{
		cout << c << " ";
	}
	cout << endl;
	cout << "偶数：";
	for (const auto& c : de_22)
	{
		cout << c << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}








