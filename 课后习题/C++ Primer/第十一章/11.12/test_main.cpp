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
	vector<pair<string, int>> ve_pair;
	string word;
	int temp = 0;

	while (cin >> word >> temp)
	{
		//pair<string, int> text;
		//text.first = word;
		//text.second = temp;
		//ve_pair.push_back(text);

		ve_pair.push_back(std::make_pair(word, temp));
	}
	
	for (const auto& c : ve_pair)
	{
		cout << c.first << "\t" << c.second << endl;
	}

	cout << endl;


	cout << endl;
	system("pause");
	return 0;
}



