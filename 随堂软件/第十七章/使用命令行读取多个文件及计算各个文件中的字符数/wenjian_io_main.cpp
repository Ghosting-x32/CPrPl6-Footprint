#include<iostream>
#include<fstream>
#include<cstdlib>

using namespace std;



//win11ϵͳ��ʹ�����������
/*
�û�����------C:\Users\admin>"cd /d E:\VS\��ϰ����һ��\x64\Debug"-----""���Ų������û�������

����ϵͳ����--E:\VS\��ϰ����һ��\x64\Debug>"��ϰ.exe"-------argc==1�����
����ϵͳ����--Usage: ��ϰ.exe filename[s]
			  E:\VS\��ϰ����һ��\x64\Debug>"��ϰ.exe paris.txt rome.txt"
����ϵͳ����--7 characters in paris.txt
			  7 characters in rome.txt
			  14 characters in all files
			  �밴���������. . .

�û�����------"�س���"

����ϵͳ����--E:\VS\��ϰ����һ��\x64\Debug>

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