#include<iostream>
#include<fstream>
#include<cstdlib>
#include<string>

int main()
{
	using namespace std;
	string wjm;
	ifstream inFile;
	cout << "请输入你的文件名：";
	getline(cin, wjm);
	inFile.open(wjm);
	if (!inFile.is_open())
	{
		cout << "程序无法打开名为" << wjm << "的文件！！！\a\a\n";
		system("pause");
		exit(0);
	}
	int zg = 0;
	int bd = 0;
	int kb = 0;
	int wz = 0;
	char zw;
	while (inFile.good())
	{
		inFile.get(zw);
		++zg;
		cout << zw;
		if (ispunct(zw))
			++bd;
		else if (isspace(zw))
			++kb;
		else
			++wz;
	}
	if (inFile.eof())
		cout << "\n作文读取完毕！！！\a\a\n\n";
	else
		cout << "不知道什么原因导致读取结束！！！\a\a\a\n\n";

	if (zg == 0)
		cout << "该作文没有任何内容！！！\a\a\a\n\n";
	else
	{
		cout << "作文总共有" << zg << "个字符!\n";
		cout << "其中文字个数是: " << wz << endl;
		cout << "标点符号个数是: " << bd << endl;
		cout << "空白的个数是: " << kb << endl;
	}

	inFile.close();
	system("pause");
	return 0;
}


