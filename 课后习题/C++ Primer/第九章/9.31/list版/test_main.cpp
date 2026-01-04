#include<iostream>
#include<vector>
#include<string>
#include<iterator>
#include<cstddef>
#include<list>
#include<deque>
#include<forward_list>





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
using std::forward_list;







int main()
{
	list<int> vi = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	auto iter = vi.begin();
	while (iter != vi.end())
	{
		if (*iter % 2 == 1)
		{
			iter = vi.insert(iter, *iter);
			++iter;
			++iter;

		}
		else
		{
			iter = vi.erase(iter);
		}

	}
	for (const auto& c : vi)
	{
		cout << c << " ";
	}

	cout << endl;


	system("pause");
	return 0;
}








