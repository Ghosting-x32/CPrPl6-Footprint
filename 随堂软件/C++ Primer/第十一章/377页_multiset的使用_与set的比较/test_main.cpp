#include<iostream>
#include<vector>
#include<string>
#include<iterator>
#include<cstddef>//提供size_t
#include<algorithm>
#include<numeric>//提供算术的算法
#include<functional>//提供bind（多元谓词与一元谓词的转换）
#include<fstream>
#include<utility>//提供pair
#include<map>
#include<set>
#include<cctype>







using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::vector;
using std::string;
using std::begin;
using std::end;
using std::size_t;
using std::map;
using std::set;









int main()
{
	vector<int> ivec;
	for (vector<int>::size_type i = 0; i != 10; ++i)
	{
		ivec.push_back(i);
		ivec.push_back(i);
	}
	set<int> iset(ivec.begin(), ivec.end());
	std::multiset<int> miset(ivec.begin(), ivec.end());

	for (const auto& c : ivec)
	{
		cout << c << " ";
	}
	cout << endl;

	for (const auto& c : iset)
	{
		cout << c << " ";
	}
	cout << endl;

	for (const auto& c : miset)
	{
		cout << c << " ";
	}
	cout << endl;



	cout << endl;
	system("pause");
	return 0;
}



