#include<iostream>
#include<vector>
#include<string>
#include<iterator>
#include<cstddef>
#include<cctype>
#include<initializer_list>
#include<cstdlib>






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



inline bool isShorter(const string& s1, const string& s2)
{
	return s1.size() < s2.size();

}




int main()
{
	
	string str1("aaa");
	string str2("bbbb");



	if (isShorter(str1, str2))
	{
		cout << str1 << endl;

	}
	else
	{
		cout << str2 << endl;
	}



	system("pause");
	return 0;

}

