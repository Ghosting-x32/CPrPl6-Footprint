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
	map<int, int> ma_int;
	ma_int[1] = 20;
	ma_int[2] = 30;

	map<int, int>::iterator it = ma_int.begin();
	++it;
	it->second = 80;

	it = ma_int.begin();
	while (it != ma_int.end())
	{
		cout << it->first << "\t" << it->second << endl;
		++it;
	}
	cout << endl;


	cout << endl;
	system("pause");
	return 0;
}



