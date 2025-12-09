#include<iostream>
#include<string>


using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
	//string s;
	//cin >> s;忽略输入流里面开头的空白，从第一个真正的字符开始读取，直到遇见下一处空白为止
	//cout << s << endl;输入“     Hello World!     ”,输出是“Hello”
	

	string s1, s2;
	cin >> s1 >> s2;
	cout << s1 << s2 << endl;//输入“     Hello World!     ”,输出是“HelloWorld!”
	//"Hello"储存到了s1,"World!"储存到了s2

	system("pause");
	return 0;
}