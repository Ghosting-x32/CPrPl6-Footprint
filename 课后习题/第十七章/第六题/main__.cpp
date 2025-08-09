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
		auto size = filesystem::file_size("dat.txt");//判断文档里面有无数据
		
		if (size == 0)
		{
			cout << "文档为空！" << endl;
			fin.close();//解决了遗留问题
			//每一次操作文件必须确保上一次操作文件后关闭了文件
			
		}
		else
		{
			cout << "文档里面有如下数据：" << endl;
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
		cout << "请输入你想要创建的项目：" << endl;
		cout << "1.employee\n2.fink\n3.manager\n4.highfink\n0.结束创建\n";
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
		auto size1 = filesystem::file_size("dat.txt");//判断文档里面有无数据

		if (size1 == 0)
		{
			cout << "文档为空！" << endl;

		}
		else
		{
			//fin.seekg(0);
			cout << "文档里面有如下数据：" << endl;
			while (fin.get(ch1))//遗留未能解决的问题
				//初始文档为空时，添加数据之后，不能显示文档内容，但文档中确实添加了数据
				//但是初始文档不为空时，添加数据之后，能显示出添加之前和添加之后的所有内容
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