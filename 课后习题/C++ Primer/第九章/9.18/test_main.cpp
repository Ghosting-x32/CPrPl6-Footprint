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
	string world;
	deque<string> de_aa;

	while (cin >> world)
	{
		de_aa.push_front(world);
	}

	for (const auto& c : de_aa)
	{
		cout << c << " ";
	}
	cout << endl;


	system("pause");
	return 0;
}








