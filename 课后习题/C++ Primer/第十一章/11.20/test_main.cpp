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

	使用 insert 操作的方式是：构造一个pair(单词,1)，用insert 将其插入容
器，返回一个pair。若单词已存在，则返回pair 的second 成员为false，表示
插入失败，程序员还需通过返回pair 的first 成员（迭代器）递增已有单词的计
数器。判断单词是否已存在，并进行相应操作的工作完全是由程序员负责的。
使用下标操作的方式是：以单词作为下标获取元素值，若单词已存在，则提取
出已有元素的值；否则，下标操作将pair(单词,0)插入容器，提取出新元素的值。
单词是否已存在的相关处理完全是由下标操作处理的，程序员不必关心，直接访问
提取出的值就行了。
显然，对于单词计数问题来说，下标操作更简洁易读。

*/




int main()
{




	map<string, size_t> word_count;
	string word;
	while (cin >> word)
	{
		auto ret = word_count.insert({ word, 1 });
		if (!ret.second)
		{
			++ret.first->second;
		}
	}

	for (const auto& c : word_count)
	{
		cout << c.first << "\t" << c.second << endl;
	}



	cout << endl;
	system("pause");
	return 0;
}



