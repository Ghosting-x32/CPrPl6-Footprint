#include<iostream>
#include<vector>
#include<string>
#include<iterator>
#include<cstddef>
#include<list>
#include<deque>
#include<forward_list>





using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::vector;
using std::string;
using std::begin;
using std::end;
using std::size_t;
using std::list;
using std::deque;
using std::forward_list;



void func_str(string& s, const string& oldVal, const string& newVal);



int main()
{
	string str1("aaathocccthofff");
	string str2("tho");
	string str3("though");

	func_str(str1, str2, str3);

	cout << str1 << endl;


	string str4("bbbthrujjjthrukkk");
	string str5("thru");
	string str6("through");


	func_str(str4, str5, str6);

	cout << str4 << endl;



	system("pause");
	return 0;
}



void func_str(string& s, const string& oldVal, const string& newVal)
{
	auto s_size = s.size();
	auto oldVal_size = oldVal.size();
	if (s_size == 0 || oldVal_size == 0)
	{
		return;
	}

	auto iter = s.begin();

	while (iter <= s.end() - oldVal_size)
	{
		auto iter1 = iter;
		auto iter2 = oldVal.begin();

		while (iter2 != oldVal.end() && *iter1 == *iter2)
		{
			++iter1;
			++iter2;
		}
		if (iter2 == oldVal.end())
		{
			iter = s.erase(iter, iter1);

			if (newVal.size() != 0)
			{
				iter2 = newVal.end();

				while (iter2 > newVal.begin())
				{
					--iter2;
					iter = s.insert(iter, *iter2);
				}
				iter += newVal.size();
			}
			

		}
		else
		{
			++iter;
		}
		

	}


}












//答案
void replace_string(string& s, const string& oldVal, const string
	& newVal)
{
	auto l = oldVal.size();
	if (!l) // 要查找的字符串为空
		return;
	auto iter = s.begin();
	while (iter <= s.end() - l) { // 末尾少于oldVal 长度的部分无须检查
		auto iter1 = iter;
		auto iter2 = oldVal.begin();
		// s 中iter 开始的子串必须每个字符都与oldVal 相同
		while (iter2 != oldVal.end() && *iter1 == *iter2) {
			iter1++;
			iter2++;
		}
		if (iter2 == oldVal.end()) { // oldVal 耗尽——字符串相等
			iter = s.erase(iter, iter1); // 删除s 中与oldVal 相等部分
			if (newVal.size()) { // 替换子串是否为空
				iter2 = newVal.end(); // 由后至前逐个插入newVal 中的字符
				do {
					iter2--;
					iter = s.insert(iter, *iter2);
				} while (iter2 > newVal.begin());
			}
			iter += newVal.size(); // 迭代器移动到新插入内容之后
		}
		else iter++;
	}
}
