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
	int ia[] = { 0, 1, 2, 3, 5, 8, 13, 21, 55, 89 };
	forward_list<int> forli_aa(begin(ia), end(ia));


	cout << "vector容器当前元素: ";
	for (const auto& c : forli_aa)
	{
		cout << c << " ";
	}
	cout << endl;


	auto prev = forli_aa.before_begin();
	auto curr = forli_aa.begin();

	while (curr != forli_aa.end())
	{
		if (*curr % 2 == 1)
		{
			curr = forli_aa.erase_after(prev);
		}
		else
		{
			prev = curr;
			++curr;
		}


	}



	cout << "list容器当前元素: ";
	for (const auto& c : forli_aa)
	{
		cout << c << " ";
	}
	cout << endl;




	system("pause");
	return 0;
}








