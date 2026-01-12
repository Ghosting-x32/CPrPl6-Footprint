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







int main()
{
	
	map<string, list<string::size_type>> ma_li;

	for (string::size_type i = 1; i < 10; ++i)
	{
		ma_li["hello"].push_back(i);
	}

	for (const auto& c : ma_li)
	{
		cout << c.first << "\n";
		for (const auto& d : c.second)
		{
			cout << d << " ";
		}

		cout << endl;
		cout << endl;
	}





	cout << endl;
	system("pause");
	return 0;
}



