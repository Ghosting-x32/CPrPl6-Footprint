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



void elimDups(list<string>& words);





int main()
{
	std::ifstream input("aaa.txt");
	std::istream_iterator<string> input_iter(input), eof;
	std::ostream_iterator<string> output_iter(cout, " ");

	list<string> li_aa;

	std::copy(input_iter, eof, std::back_inserter(li_aa));
	std::copy(li_aa.begin(), li_aa.end(), output_iter);
	cout << endl;

	elimDups(li_aa);
	std::copy(li_aa.begin(), li_aa.end(), output_iter);

	cout << endl;
	system("pause");
	return 0;
}


void elimDups(list<string>& words)
{
	words.sort();
	words.unique();

}
