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



/*

对 map 进行下标操作，应使用其key_type，即关键字的类型。
而下标操作返回的类型是mapped_type，即关键字关联的值的类型。
示例如下：
map 类型：map<string, int>
用来进行下标操作的类型：string
下标操作返回的类型：int
*/



int main()
{
	map<string, int> ma_aa;
	ma_aa["hhh"] = 2;

	auto it = ma_aa["hhh"];

	cout << endl;
	system("pause");
	return 0;
}



