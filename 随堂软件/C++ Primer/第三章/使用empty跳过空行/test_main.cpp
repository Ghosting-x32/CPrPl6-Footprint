#include<iostream>
#include<string>


using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
	string line;
	int a = 0;
	cin >> a;

	//cin.clear();-----解决问题1的办法(1)
	//while (cin.get() != '\n')
	//{
	//	continue;
	//}
	//cout << a << endl;


	while (getline(cin, line))//从给定的输入流中读取内容，直到遇到换行符为止（输入流头部的换行符被读取）
	{//输入流头部的换行符刚被读取，就存入一个空字符到line中，随后该换行符导致读取结束，走了一遍循环---问题1
		//但是输入流中的换行符并没有储存到line中，而是被丢掉
		if (!line.empty())//-----解决问题1的办法(2)
		{
			cout << line << endl;
		}
	}

	system("pause");
	return 0;
}