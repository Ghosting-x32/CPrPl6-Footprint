#include<iostream>
#include<fstream>
#include<cstdlib>

using namespace std;



//win11系统中使用下面的命令
/*
用户输入------C:\Users\admin>"cd /d E:\VS\练习（第一）\x64\Debug"-----""引号部分是用户的输入

电脑系统反馈--E:\VS\练习（第一）\x64\Debug>"练习.exe"-------argc==1的情况
电脑系统反馈--Usage: 练习.exe filename[s]
			  E:\VS\练习（第一）\x64\Debug>"练习.exe paris.txt rome.txt"
电脑系统反馈--7 characters in paris.txt
			  7 characters in rome.txt
			  14 characters in all files
			  请按任意键继续. . .

用户输入------"回车键"

电脑系统反馈--E:\VS\练习（第一）\x64\Debug>

*/
int main(int argc, char* argv[])
{
	if (argc == 1)
	{
		cerr << "Usage: " << argv[0] << " filename[s]";
		exit(EXIT_FAILURE);
	}

	ifstream fin;
	long count;
	long total = 0;
	char ch;

	for (int file = 1; file < argc; file++)
	{
		fin.open(argv[file]);
		if (!fin.is_open())
		{
			cerr << "Could not open " << argv[file] << endl;
			fin.clear();
			continue;

		}

		count = 0;
		while (fin.get(ch))
		{
			count++;
		}

		cout << count << " characters in " << argv[file] << endl;
		total += count;
		fin.clear();
		fin.close();


	}

	cout << total << " characters in all files\n";






	system("pause");
	return 0;
}