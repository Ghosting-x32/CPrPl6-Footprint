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
multimap 的数据结构是红黑树，它维护了元素的关键字的默认序。例如，对
字符串关键字（作者），红黑树会维护它们的字典序。当我们遍历multimap（如遍
历[begin(), end())，或更简单地使用范围for）时，就是按关键字的字典序来
访问元素。
因此，上一题的print_books 实际上已经实现了按字典序打印作者列表和他
们的作品。
但是，当我们要求的不是关键字的默认序（运算符<定义的顺序）时，就要复杂
一些。由于sort 算法要求给定的两个迭代器是随机迭代器，关联容器的迭代器不符
合这一要求，所以不能直接对其使用sort 算法。其实这不难理解，关联容器的根本
特征就是维护了关键字的默认序，从而实现了按关键字的插入、删除和查找。是不
可能通过sort 使其内部元素呈现出另外一种顺序的。只有本身不关心元素值的顺序
容器，才可能随意安排元素顺序（位置）。我们可以在定义multimap 时使用自己定
义的比较操作所定义的关键字的序，而不是使用<定义的序，但这只是令multimap
以另外一种序来维护关键字，仍然不可能在使用multimap 的过程中来改变关键字
顺序。为此，我们只能将multimap 中的元素拷贝到一个顺序容器（如vector）
中，对顺序容器执行sort 算法，来获得关键字的其他序。
*/



int main()
{
	std::multimap<string, string> authors;
	authors.insert({ "aaa", "bbb" });
	authors.insert({ "aaa", "ccc" });

	for (const auto& c : authors)
	{
		cout << c.first << "\t" << c.second << endl;
	}



	cout << endl;
	system("pause");
	return 0;
}



