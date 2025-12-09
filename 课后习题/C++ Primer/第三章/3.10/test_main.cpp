#include<iostream>
#include<string>
#include<cctype>


using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
	string str;
	cout << "请输入一个包含标点符号的字符串:" << endl;
	getline(cin, str);

	cout << "你输入的字符串是: " << str << endl;
	string str1;

	for (auto& c : str)
	{
		if (!ispunct(c))
		{
			str1 += c;
		}

	}

	cout << "去掉标点符号后的字符串是: " << str1 << endl;




	system("pause");
	return 0;
}