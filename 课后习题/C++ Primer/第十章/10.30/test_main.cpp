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
	vector<int> ve_int;
	std::istream_iterator<int> input_iter(cin), eof;
	std::copy(input_iter, eof, std::back_inserter(ve_int));

	std::sort(ve_int.begin(), ve_int.end(),
		[](const int& val1, const int& val2)
		{
			return val1 > val2;
		}	
	);

	std::ostream_iterator<int> output_iter(cout, " ");

	//输出方法1：
	//auto it = ve_int.begin();
	//while (it != ve_int.end())
	//{
	//	*output_iter++ = *it;
	//	cout << " ";
	//	++it;
	//}



	//输出方法2：
	std::copy(ve_int.begin(), ve_int.end(), output_iter);

	cout << endl;
	

	


	cout << endl;
	system("pause");
	return 0;
}


