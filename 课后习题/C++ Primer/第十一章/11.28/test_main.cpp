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
#include<list>
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
using std::list;
using std::pair;






int main()
{
	map<string, vector<int>> ma_aa;

	ma_aa.insert({ "aaa", {1, 2, 3, 4} });

	auto ret = ma_aa.find("aaa");

	if (ret != ma_aa.end())
	{
		for (const auto& c : ret->second)
		{
			cout << c << " ";
		}
		cout << endl;
	}




	cout << endl;
	system("pause");
	return 0;
}



