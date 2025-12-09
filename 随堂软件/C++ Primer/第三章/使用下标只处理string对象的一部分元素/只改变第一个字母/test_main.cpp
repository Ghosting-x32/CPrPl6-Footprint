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

	if (!s.empty())
	{
		s[0] = toupper(s[0]);//如果c是小写字母，输出对应的大写字母，否则原样输出
	}
	
	cout << s << endl;




	system("pause");
	return 0;
}