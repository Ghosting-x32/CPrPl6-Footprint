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

	vector<int> ve2{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	list<int> li2;

	std::copy(ve2.crbegin() + 2, ve2.crend() - 3, std::back_inserter(li2));

	std::ostream_iterator<int> output_iter(cout, " ");

	std::copy(li2.begin(), li2.end(), output_iter);



	cout << endl;
	system("pause");
	return 0;
}


