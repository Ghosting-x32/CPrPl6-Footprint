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
		exit(EXIT_FAILURE);//ֱ���˳�����
	}

	string item;
	int count = 0;
	getline(ifs1, item, ':');//Ĭ��������\n�������룬���ڸ���Ϊ����:��������,\n��Ϊ��ͨ���ַ�
	while (ifs1)
	{
		++count;
		cout << count << ": " << item << endl;//���item��ֵΪ����\n
		getline(ifs1, item, ':');

	}

	ifs1.close();





	system("pause");
	return 0;
}