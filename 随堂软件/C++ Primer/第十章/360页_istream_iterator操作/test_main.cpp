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
	std::istream_iterator<int> in_iter(cin), eof;
	vector<int> vec(in_iter, eof);


	for (const auto& c : vec)
	{
		cout << c << "\t";
	}
	cout << endl;



	cout << endl;
	system("pause");
	return 0;
}


