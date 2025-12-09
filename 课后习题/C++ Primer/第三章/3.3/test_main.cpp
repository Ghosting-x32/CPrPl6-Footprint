 #include<iostream>
#include<string>


using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
	string word, line;
	cout << "请选择读取字符串的方式：1 表示逐词读取，2 表示整行读取" << endl;
	char ch;
	cin >> ch;
	// 清空输入缓冲区
	cin.clear();
	cin.sync();
	while (cin.get() != '\n')//清除掉输入流中之前输入多余的内容
	{
		continue;
	}

	if (ch == '1')
	{
		cout << "请输入字符串： Welcome to C++ family! " << endl;
		cin >> word;
		cout << "系统读取的有效字符串是：" << endl;
		cout << word << endl;
		
	}
	// 清空输入缓冲区
	cin.clear();
	cin.sync();



	if (ch == '2')
	{
		cout << "请输入字符串： Welcome to C++ family! " << endl;
		getline(cin, line);
		cout << "系统读取的有效字符串是：" << endl;
		cout << line << endl;
		
	}

	if (ch != '1' && ch != '2')
	{
		cout << "您的输入有误！";
	}
	


	system("pause");
	return 0;
}