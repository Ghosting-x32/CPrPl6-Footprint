#include <iostream>
#include<string>
#include<fstream>

using namespace std;


int main()
{
	int a = 0;
	
	flage:
	while (true)
	{
		cout << "请输入a：" << endl;
		while (!(cin >> a))
		{
			cin.clear();
			while (cin.get() != '\n')
			{
				continue;
			}
			cout << "输入有误，请输入数字！" << endl;
		}
		
		ifstream ifs;
		ifs.open("scores.txt", ios::in);
		if (!(ifs.is_open()))
		{
			cout << "文件打开失败！" << endl;
			ifs.close();
			system("pause");
			return 0;
		}

		int id = 0;
		string name;
		string pwd;

		while (ifs >> id)//&& ifs >> name && ifs >> pwd
		{		
			if (id == a)
			{
				cout << "学号已被使用，请重新输入！" << endl;
				while (ifs.get() != '\n')
				{
					continue;
				}
				ifs.close();
				goto flage;
			}
			while (ifs.get() != '\n')
			{
				continue;
			}
		}

		break;
	}

	cout << "学号 " << a << " 未被使用，可以注册！" << endl;

	if (a != 0)
	{
		string name1;
		string pwd1;
		cout << "请输入姓名：" << endl;
		cin >> name1;
		cout << "请输入密码：" << endl;
		cin >> pwd1;
		ofstream ofs;
		ofs.open("scores.txt", ios::out | ios::app);
		ofs << a << " " << name1 << " " << pwd1 << endl;
		ofs.close();
	}








	system("pause");
	return 0;
}
