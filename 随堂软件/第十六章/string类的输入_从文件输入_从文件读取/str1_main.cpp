#include<iostream>
#include<string>
#include<fstream>
#include<cstdlib>

using namespace std;

int main()
{
	ifstream ifs1;
	ifs1.open("text111.txt", ios::in);
	if (!ifs1.is_open())
	{
		cerr << "Can't open file. Bye.\n";
		exit(EXIT_FAILURE);//直接退出程序
	}

	string item;
	int count = 0;
	getline(ifs1, item, ':');//默认是遇到\n结束输入，现在更改为遇到:结束输入,\n变为普通的字符
	while (ifs1)
	{
		++count;
		cout << count << ": " << item << endl;//最后item的值为两个\n
		getline(ifs1, item, ':');

	}

	ifs1.close();





	system("pause");
	return 0;
}