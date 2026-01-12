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










int main()
{
	map<string, size_t> word_count;
	string word;
	while (cin >> word)
	{
		++word_count[word];
	}

	for (const auto& c : word_count)
	{
		cout << c.first << "\t" << c.second << endl;

	}








	cout << endl;
	system("pause");
	return 0;
}



