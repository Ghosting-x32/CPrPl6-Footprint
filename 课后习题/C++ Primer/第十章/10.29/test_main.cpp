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
	
	

	std::ifstream input("aaa.txt");
	std::istream_iterator<string> input_iter(input), eof;
	vector<string> ve_str(input_iter, eof);

	for (const auto& c : ve_str)
	{
		cout << c << " ";
	}
	cout << endl;


	cout << endl;
	system("pause");
	return 0;
}


