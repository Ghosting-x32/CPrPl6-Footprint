#include<iostream>
#include<vector>
#include<string>
#include<iterator>
#include<cstddef>
#include<algorithm>
#include<numeric>
#include<list>
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








int main()
{
	list<string> v1;
	string world;
	std::ifstream input("aaa.txt");
	while (input >> world)
	{
		v1.push_back(world);
	}

	auto sum = std::accumulate(v1.begin(), v1.end(), string(""));

	cout << sum << endl;


	vector<int> v2(10, 10);
	auto sum_ve = std::accumulate(v2.begin(), v2.end(), 0);

	cout << sum_ve << endl;

	system("pause");
	return 0;
}


	















