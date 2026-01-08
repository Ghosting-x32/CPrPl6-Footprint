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


	vector<string> v2;
	v2.resize(v1.size());
	std::copy(v1.begin(), v1.end(), v2.begin());
	

	for (const auto& c : v2)
	{
		cout << c << " ";
	}










	cout << endl;
	system("pause");
	return 0;
}


	















