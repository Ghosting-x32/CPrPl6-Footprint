#include<iostream>
#include<fstream>
#include<cstdlib>


using namespace std;



int main(int argc, char* argv[])
{
	ifstream fin;
	fin.open(argv[1]);//�ӽ�����ִ�г�������***.exe��֮����ļ�����
	if (!fin.is_open())
	{
		cout << "��ȡ�ļ���ʧ�ܣ�" << endl;
		exit(EXIT_FAILURE);
	}

	ofstream fout(argv[2]);//���Ƶ��������ṩ�ĵ�����ڶ����ļ�����һ���ǿ�ִ���ļ���
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

