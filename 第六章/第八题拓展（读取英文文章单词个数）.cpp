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
	int wz = 0;
	string zw;
	while (inFile.good())
	{
		inFile >> zw;
		if (isalpha(zw[0]))
			++wz;	
	}
	if (inFile.eof())
		cout << "\n文章读取完毕！！！\a\a\n\n";
	else
		cout << "不知道什么原因导致读取结束！！！\a\a\a\n\n";

	if (wz == 0)
		cout << "该文章没有任何内容！！！\a\a\a\n\n";
	else
		cout << "该文章单词个数是: " << wz << endl;

	inFile.close();
	system("pause");
	return 0;
}


