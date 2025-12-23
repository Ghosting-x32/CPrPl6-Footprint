#include<iostream>
#include<vector>
#include<string>
#include<iterator>
#include<cstddef>
#include<cctype>
#include<initializer_list>






using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::begin;
using std::end;
using std::size_t;
using std::isupper;
using std::tolower;
using std::initializer_list;



bool str_subrange(const string& str1, const string& str2);



int main()
{
	string s1("abc");
	string s2("rtyd");

	if (str_subrange(s1, s2))
	{
		cout << "两个单词某个对应位置有相同的字母，或者两个单词相同!" << endl;
	}
	else
	{
		cout << "两个单词对应位置的字母没有相同的!" << endl;
	}


	system("pause");
	return 0;
}





bool str_subrange(const string& str1, const string& str2)
{
	if (str1.size() == str2.size())
	{	
		return str1 == str2;
	}

	auto size = (str1.size() < str2.size()) ? str1.size() : str2.size();

	for (decltype(size) i = 0; i != size; ++i)
	{
		if (str1[i] == str2[i])
		{
			return true;
		}
	}
	return false;//必须有，否则循环结束后，循环内没有执行过return的情况，返回值是不确定的，编译器检测不出错误

}