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
	string numbers("0123456789");
	string name("5h6rjk2");

	string::size_type pos = 0;
	while ((pos = name.find_first_of(numbers, pos)) != string::npos)
	{
		cout << "found number at index: " << pos << " elemennt is " << name[pos] << endl;
		++pos;
	}



	system("pause");
	return 0;
}















