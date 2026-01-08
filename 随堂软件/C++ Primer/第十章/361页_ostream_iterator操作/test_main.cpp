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
	std::ostream_iterator<int> out_iter(cout, " ");
	vector<int> v1(10, 25);
	for (const auto& c : v1)
	{
		*out_iter++ = c;
	}



	//std::ostream_iterator<int> out_iter(cout, " ");
	//vector<int> v1(10, 25);
	//std::copy(v1.begin(), v1.end(), out_iter);



	cout << endl;
	system("pause");
	return 0;
}


