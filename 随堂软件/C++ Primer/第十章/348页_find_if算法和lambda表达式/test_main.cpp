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
	vector<string> v1;
	string temp;
	vector<string>::size_type sz = 3;
	std::ifstream input("aaa.txt");
	while (input >> temp)
	{
		v1.push_back(temp);


	}

	for (const auto& c : v1)
	{
		cout << c << " ";
	}
	cout << endl;
	v1.push_back("aa");

	auto it = std::find_if(v1.begin(), v1.end(),
		[sz](const string& s1)
		{
			return s1.size() < sz;
		}
		);

	cout << *it << endl;


	for (const auto& c : v1)
	{
		cout << c << " ";
	}
	cout << endl;


	cout << endl;
	system("pause");
	return 0;
}












































