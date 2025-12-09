 #include<iostream>
#include<string>


using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
	//1.判断字符串是否相等

	string str1, str2;
	cout << "请输入两个字符串：(str1和str2)" << endl;
	cin >> str1 >> str2;

	if (str1 == str2)
	{
		cout << "两个字符串相等！均为: " << str1 << endl;
	}
	else
	{
		if (str1 > str2)
		{
			cout << "两个字符串不相等！" << endl << "较大的字符串是str1: " << str1 << endl;
		}
		else
		{
			cout << "两个字符串不相等！" << endl << "较大的字符串是str2: " << str2 << endl;
		}
	/*	cout << "两个字符串不相等！" << endl << "str1为: "
			<< str1 << "\tstr2为: " << str2 << endl;*/
	}



	//2.判断字符串长度是否相等

	if (str1.size() == str2.size())
	{

		cout << "两个字符串长度相等！长度均为: " << str1.size() << endl;

	}
	else
	{
		if (str1.size() > str2.size())
		{
			cout << "两个字符串长度不相等！" << endl << "较长的字符串是str1: " << str1 << "\t长度为: " << str1.size() << endl;
		}
		else
		{
			cout << "两个字符串长度不相等！" << endl << "较长的字符串是str2: " << str2 << "\t长度为: " << str2.size() << endl;
		}



	}





	system("pause");
	return 0;
}