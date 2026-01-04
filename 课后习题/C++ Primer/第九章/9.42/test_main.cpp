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
	string str;
	str.reserve(100);
	char ch = 'a';

	while (cin.get(ch) && ch != '\n')
	{
		str.push_back(ch);
	}
	cout << str << endl;



	system("pause");
	return 0;
}








