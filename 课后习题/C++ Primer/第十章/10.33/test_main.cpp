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
	std::ofstream output_bb("bbb.txt");
	std::ofstream output_cc("ccc.txt");

	std::istream_iterator<int> input_iter(input), eof;

	std::ostream_iterator<int> output_iter_bb(output_bb, " ");
	std::ostream_iterator<int> output_iter_cc(output_cc, "\n");

	auto it = input_iter;
	while (it != eof)
	{
		auto temp = *it;
		if (temp % 2 == 1)
		{
			*output_iter_bb++ = temp;
		}
		else
		{
			*output_iter_cc++ = temp;
		}
	
		++it;


	}


	

	
	input.close();
	output_bb.close();
	output_cc.close();

	cout << endl;
	system("pause");
	return 0;
}


