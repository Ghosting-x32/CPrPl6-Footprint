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






bool func_str(const string& s1);




int main()
{
	vector<string> v1;
	string temp;
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

	std::stable_sort(v1.begin(), v1.end(),
		[](const string& s1, const string& s2)
		{
			return s1.size() < s2.size();
		}
	);

	for (const auto& c : v1)
	{
		cout << c << " ";
	}
	cout << endl;



	cout << endl;
	system("pause");
	return 0;
}












































