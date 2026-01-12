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
	std::multimap<string, string> authors;
	authors.insert({ "aaa", "bbb" });
	authors.insert({ "aaa", "ccc" });

	string search_item("aaa");


	auto it = authors.find(search_item);
	

	if (it != authors.end())
	{
		auto ret = authors.erase(search_item);
		cout << "成功删除了 " << ret << " 个" << search_item << endl;
	}
	else
	{
		cout << "容器中没有找到键值为: " << search_item << " 的元素" << endl;
	}



	cout << endl;
	system("pause");
	return 0;
}



