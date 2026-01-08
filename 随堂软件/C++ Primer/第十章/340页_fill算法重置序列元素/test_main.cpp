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
	list<string> v1;
	string world;
	std::ifstream input("aaa.txt");
	while (input >> world)
	{
		v1.push_back(world);
	}

	for (const auto& c : v1)
	{
		cout << c << " ";
	}
	cout << endl;

	list<string>::iterator it = v1.begin();
	for (list<string>::size_type i = 0; i <= v1.size() / 2; ++i)
	{
		++it;
	}


	std::fill(v1.begin(), it, "aaa");

	for (const auto& c : v1)
	{
		cout << c << " ";
	}
	cout << endl;
	auto aaa = std::accumulate(v1.begin(), v1.end(), string("bbb"));



	cout << aaa << endl;









	cout << endl;
	system("pause");
	return 0;
}


	















