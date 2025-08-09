#include<iostream>
#include<fstream>
#include<cstdlib>


using namespace std;



int main(int argc, char* argv[])
{
	ifstream fin;
	fin.open(argv[1]);//从紧跟可执行程序名（***.exe）之后的文件复制
	if (!fin.is_open())
	{
		cout << "读取文件打开失败！" << endl;
		exit(EXIT_FAILURE);
	}

	ofstream fout(argv[2]);//复制到命令行提供的第三项（第二个文件）第一项是可执行文件名
	char ch;
	

	while (fin.get(ch))
	{
		fout.put(ch);
	}

	fin.close();
	fout.close();

	cout << "Done!" << endl;







	system("pause");
	return 0;
}

