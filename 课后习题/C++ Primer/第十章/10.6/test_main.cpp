#include<iostream>
#include<vector>
#include<string>
#include<iterator>
#include<cstddef>
#include<algorithm>
#include<numeric>
#include<list>
#include<fstream>
#include<cstring>








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








int main()
{
	vector<int> v1;

	std::fill_n(std::back_inserter(v1), 10, 596);
	for (const auto& c : v1)
	{
		cout << c << "\t";
	}
	cout << endl;


	std::fill_n(v1.begin(), v1.size(), 0);


	for (const auto& c : v1)
	{
		cout << c << "\t";
	}
	cout << endl;







	cout << endl;
	system("pause");
	return 0;
}


















