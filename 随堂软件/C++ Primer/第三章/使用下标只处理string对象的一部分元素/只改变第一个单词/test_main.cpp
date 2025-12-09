#include<iostream>
#include<string>
#include<cctype>


using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
	string s("some string");


	for (decltype(s.size()) index = 0; index != s.size() && !isspace(s[index]); ++index)//isspace(c):当c是空白时为真（即c是空格、横向制表符、纵向制表符、回车符、换行符、进纸符中的一种）
	{
		s[index] = toupper(s[index]);//如果c是小写字母，输出对应的大写字母，否则原样输出
	}


	
	cout << s << endl;




	system("pause");
	return 0;
}