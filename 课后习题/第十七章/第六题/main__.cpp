#include<iostream>
#include<string>
#include<fstream>
#include<filesystem>

#include"abstr_emp.h"
#include"employee.h"
#include"fink.h"
#include"highfink.h"
#include"manager.h"


using namespace std;

const int MAX = 10;

int main()
{
	char ch;
	ifstream fin;
	fin.open("dat.txt");
	if (fin.is_open())
	{
		auto size = filesystem::file_size("dat.txt");//�ж��ĵ�������������
		
		if (size == 0)
		{
			cout << "�ĵ�Ϊ�գ�" << endl;
			fin.close();//�������������
			//ÿһ�β����ļ�����ȷ����һ�β����ļ���ر����ļ�
			
		}
		else
		{
			cout << "�ĵ��������������ݣ�" << endl;
			while (fin.get(ch))
			{
				cout << ch;

			}
			cout << endl;
			fin.close();

		}
		

	}

	abstr_emp* pc[MAX];
	int i;
	for (i = 0; i < MAX; i++)
	{
		cout << "����������Ҫ��������Ŀ��" << endl;
		cout << "1.employee\n2.fink\n3.manager\n4.highfink\n0.��������\n";
		int sele;
		cin >> sele;
		switch (sele)
		{
		case 1: pc[i] = new employee;
			break;
		case 2:pc[i] = new fink;
			break;
		case 3:pc[i] = new manager;
			break;
		case 4:pc[i] = new highfink;
			break;
		case 0:goto flag;

		}

		pc[i]->SetAll();

		pc[i]->writeall();


	}

	flag:fin.clear();
	fin.open("dat.txt");
	char ch1;
	if (fin.is_open())
	{
		auto size1 = filesystem::file_size("dat.txt");//�ж��ĵ�������������

		if (size1 == 0)
		{
			cout << "�ĵ�Ϊ�գ�" << endl;

		}
		else
		{
			//fin.seekg(0);
			cout << "�ĵ��������������ݣ�" << endl;
			while (fin.get(ch1))//����δ�ܽ��������
				//��ʼ�ĵ�Ϊ��ʱ���������֮�󣬲�����ʾ�ĵ����ݣ����ĵ���ȷʵ���������
				//���ǳ�ʼ�ĵ���Ϊ��ʱ���������֮������ʾ�����֮ǰ�����֮�����������
			{
				
				cout << ch1;

			}
			cout << endl;
			fin.close();

		}


	}

	for (int g = 0; g < i; g++)
	{
		delete pc[g];

	}





	system("pause");
	return 0;
}