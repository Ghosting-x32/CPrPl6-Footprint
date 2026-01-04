#include<iostream>
#include<vector>
#include<string>
#include<iterator>
#include<cstddef>
#include<list>
#include<deque>




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







int main()
{
	vector<int> v1(10, 20);
	vector<int> v2(10, 10);

	if (v1 == v2)
	{
		cout << "v1 = v2" << endl;
	}
	else if (v1 > v2)
	{
		cout << "v1 > v2" << endl;
	}
	else
	{
		cout << "v1 < v2" << endl;
	}



	


	system("pause");
	return 0;
}








