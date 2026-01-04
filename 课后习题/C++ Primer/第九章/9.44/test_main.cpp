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

	decltype(s.size()) subscript = 0;


	while ((subscript = s.find(oldVal, subscript)) != string::npos)
	{
		if (newVal.size() != 0)
		{
			s.replace(subscript, oldVal_size, newVal);
			subscript += newVal.size();
		}

	}


}

//答案
//int p = 0;
//while ((p = s.find(oldVal, p)) != string::npos) { // 在s 中查找oldVal
//	s.replace(p, oldVal.size(), newVal);// 将找到的子串替换为newVal 的内容
//	p += newVal.size(); // 下标调整到新插入内容之后
//}











