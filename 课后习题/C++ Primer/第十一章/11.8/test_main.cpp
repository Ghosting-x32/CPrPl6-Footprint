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


/*
使用 vector 保存不重复单词，需要用find 查找新读入的单词是否已在
vector 中，若不在（返回尾后迭代器），才将单词加入vector。
而使用set，检查是否重复的工作是由set 模板负责的，程序员无须编写对应
代码，程序简洁很多。
更深层次的差别，vector 是无序线性表，find 查找指定值只能采用顺序查找
方式，所花费的时间与vector.size()呈线性关系。而set 是用红黑树实现的，
花费的时间与vector.size()呈对数关系。当单词数量已经非常多时，set 的性
能优势是巨大的。
当然，vector 也不是毫无用处。它可以保持单词的输入顺序，而set 则不能，
遍历set，元素是按值的升序被遍历的。

*/






int main()
{
	
	vector<string> vec_aa;
	string word;
	while (cin >> word)
	{
		auto pos = std::find(vec_aa.begin(), vec_aa.end(), word);

		if (pos == vec_aa.end())
		{

			vec_aa.push_back(word);

		}

	}

	for (const auto& c : vec_aa)
	{
		cout << c << " ";
	}

	cout << endl;







	cout << endl;
	system("pause");
	return 0;
}



