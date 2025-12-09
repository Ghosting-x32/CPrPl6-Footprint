#include<iostream>
#include<string>
#include<cctype>


using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
	string str("some string");
	for (auto c : str)
	{
		cout << c << endl;
	}

	string s("Hello World!!!");
	decltype(s.size()) punct_cnt = 0;//用于储存s中有多少个标点符号
	//自动推断punct_cnt变量的类型，为string::size_type(s.size()返回的类型)
	for (auto c : s)
	{
		if (ispunct(c))//当c是标点符号时为真（即c不是控制字符、数字、字母、可打印空白中的一种）
		{
			++punct_cnt;
		}
	}

	cout << punct_cnt << " punctuation characters in " << s << endl;




	system("pause");
	return 0;
}