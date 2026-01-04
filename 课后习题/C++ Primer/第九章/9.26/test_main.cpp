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
	int ia[] = { 0, 1, 2, 3, 5, 8, 13, 21, 55, 89 };
	
	vector<int> ve_aa(begin(ia), end(ia));
	list<int> li_aa(begin(ia), end(ia));


	cout << "vector容器当前元素: ";
	for (const auto& c : ve_aa)
	{
		cout << c << " ";
	}
	cout << endl;

	cout << "list容器当前元素: ";
	for (const auto& c : li_aa)
	{
		cout << c << " ";
	}
	cout << endl;

	auto it = li_aa.begin();
	while (it != li_aa.end())
	{
		if (*it % 2 == 1)
		{
			it = li_aa.erase(it);
		}
		else
		{
			++it;
		}
		

	}

	auto iu = ve_aa.begin();
	while (iu != ve_aa.end())
	{
		if (*iu % 2 == 0)
		{
			iu = ve_aa.erase(iu);
		}
		else
		{
			++iu;
		}

	}

	cout << "vector容器当前元素: ";
	for (const auto& c : ve_aa)
	{
		cout << c << " ";
	}
	cout << endl;

	cout << "list容器当前元素: ";
	for (const auto& c : li_aa)
	{
		cout << c << " ";
	}
	cout << endl;





	system("pause");
	return 0;
}








