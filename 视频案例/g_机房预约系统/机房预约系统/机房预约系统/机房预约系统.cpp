//#include <Windows.h>

#include<iostream>
#include<string>
#include<fstream>

#include"Identity.h"
#include"Student.h"
#include"Teacher.h"
#include"Manager.h"
#include"GlobalFile.h"

using namespace std;

//string GbkToUtf8(const std::string& gbkStr);//控制台文字格式为GBK，文档文本文字格式为UTF-8，该问题已通过改变文档文本文字格式为GBK解决
void LoginIn(string filename, int type);//登录函数--操作的文件名、用户的身份
void managerMenu(Identity*& manager);//管理员菜单函数
void studentMenu(Identity*& student);//学生代表菜单函数
void teacherMenu(Identity*& teacher);//老师菜单函数




int main()
{
	//SetConsoleOutputCP(CP_UTF8);//将控制台的文字格式改为UTF-8
	//SetConsoleCP(CP_UTF8);

	int select = 0;
	while (true)
	{
		cout << "======================  欢迎来到传智播客机房预约系统  ======================" << endl;
		cout << endl << "请输入你的身份" << endl;
		cout << "\t\t---------------------------------\n";
		cout << "\t\t|                                |\n";
		cout << "\t\t|           1.学生代表           |\n";
		cout << "\t\t|                                |\n";
		cout << "\t\t|           2.老    师           |\n";
		cout << "\t\t|                                |\n";
		cout << "\t\t|           3.管 理 员           |\n";
		cout << "\t\t|                                |\n";
		cout << "\t\t|           0.退    出           |\n";
		cout << "\t\t|                                |\n";
		cout << "\t\t---------------------------------\n";
		cout << "请输入你的选择：";

		while (!(cin >> select))
		{
			cin.clear();
			while (cin.get() != '\n')
			{
				continue;
			}
			cout << "输入有误，请输入数字！" << endl;
		}

		switch (select)
		{
		case 1://学生代表
		{
			LoginIn(STUDENT_FILE, 1);

		}
			break;
		case 2://老师
		{
			LoginIn(TEACHER_FILE, 2);

		}
			break;
		case 3://管理员
		{
			LoginIn(ADMIN_FILE, 3);

		}
			break;
		case 0://退出
		{
			cout << "欢迎下次使用！" << endl;
			system("pause");
			return 0;
		}
			break;
		default:
		{
			cout << "输入有误，请重新输入！" << endl;
			system("pause");
			system("cls");
		}
			break;
		}
	}
	







	system("pause");
	return 0;
}


void LoginIn(string filename, int type)
{
	Identity* person = NULL;//创建父类指针指向子类
	ifstream ifs1;
	ifs1.open(filename, ios::in);
	if (!(ifs1.is_open()))
	{
		cout << "打开失败，文件不存在！" << endl;
		ifs1.close();
		system("pause");
		system("cls");
		return;
	}

	char ch;
	ifs1 >> ch;
	if (ifs1.eof())
	{
		cout << "文件数据为空！" << endl;
		ifs1.close();
		system("pause");
		system("cls");
		return;
	}
	ifs1.putback(ch);

	int id = 0;
	string name;
	string pwd;

	//ofstream ofs1;
	//ofs1.open("text1.txt", ios::out);
	//ofs1 << "张三" << endl;
	//ofs1 << "李四" << endl;
	//ofs1 << "王五" << endl;
	//ofs1 << "赵六" << endl;
	//ofs1 << "王二" << endl;
	//ofs1 << "吴九" << endl;
	//ofs1.close();


	if (type == 1)
	{
		cout << "请输入你的学号：" << endl;
		while (!(cin >> id))
		{
			cin.clear();
			while (cin.get() != '\n')
			{
				continue;
			}
			cout << "输入错误，请输入数字！" << endl;
		}

	}
	else if (type == 2)
	{
		cout << "请输入你的职工号：" << endl;
		while (!(cin >> id))
		{
			cin.clear();
			while (cin.get() == '\n')
			{
				continue;
			}
			cout << "输入错误，请输入数字！" << endl;
		}
	}
	cout << "请输入你的姓名：" << endl;
	cin >> name;
	//string name1 = GbkToUtf8(name);//将控制台输入的GBK格式转换为文本文档输入的格式UTF-8


	cout << "请输入你的密码：" << endl;
	cin >> pwd;


	if (type == 1)
	{
		//验证学生登录
		int fId = 0;
		string fName;
		string fPwd;
		while (ifs1 >> fId && ifs1 >> fName && ifs1 >> fPwd)//文件读取的内容与用户输入的内容做对比
		{
			//cout << fName << endl;
			if (fId == id && fName == name && fPwd == pwd)
			{
				cout << "学生验证登录成功！" << endl;	
				system("pause");
				system("cls");
				ifs1.close();
				person = new Student(id, name, pwd);
				//进入学生身份子菜单
				studentMenu(person);

				return;
			}

		}



	}
	else if (type == 2)
	{
		//验证老师登录
		int fId = 0;
		string fName;
		string fPwd;
		while (ifs1 >> fId && ifs1 >> fName && ifs1 >> fPwd)//文件读取的内容与用户输入的内容做对比
		{
			//cout << fName << endl;
			if (fId == id && fName == name && fPwd == pwd)
			{
				cout << "老师验证登录成功！" << endl;				
				system("pause");
				system("cls");
				ifs1.close();
				person = new Teacher(id, name, pwd);
				//进入老师身份子菜单

				teacherMenu(person);

				return;
			}

		}


	}
	else if(type == 3)
	{
		//验证管理员登录
		string fName;
		string fPwd;
		while (ifs1 >> fName && ifs1 >> fPwd)//文件读取的内容与用户输入的内容做对比
		{
			//cout << fName << endl;
			if (fName == name && fPwd == pwd)
			{
				cout << "管理员验证登录成功！" << endl;				
				system("pause");
				system("cls");
				ifs1.close();
				person = new Manager(name, pwd);
				//进入管理员身份子菜单
				managerMenu(person);
				
				return;
			}

		}

	}


	cout << "验证登录失败！" << endl;
	system("pause");
	system("cls");
	ifs1.close();
	return;
}

//string GbkToUtf8(const std::string& gbkStr)
//{
//	int len = MultiByteToWideChar(CP_ACP, 0, gbkStr.c_str(), -1, nullptr, 0);
//	wchar_t* wstr = new wchar_t[len];
//	MultiByteToWideChar(CP_ACP, 0, gbkStr.c_str(), -1, wstr, len);
//
//	len = WideCharToMultiByte(CP_UTF8, 0, wstr, -1, nullptr, 0, nullptr, nullptr);
//	char* utf8Str = new char[len];
//	WideCharToMultiByte(CP_UTF8, 0, wstr, -1, utf8Str, len, nullptr, nullptr);
//
//	std::string result(utf8Str);
//	delete[] wstr;
//	delete[] utf8Str;
//	return result;
//}

void managerMenu(Identity*& manager)
{
	while (true)
	{
		manager->operMenu();
		Manager* man = (Manager*)manager;
		int select = 0;

		while (!(cin >> select))
		{
			cin.clear();
			while (cin.get() != '\n')
			{
				continue;
			}
			cout << "输入有误，请输入数字！" << endl;
		}

		if (select == 1)//添加账号
		{
			//cout << "添加账号" << endl;
			man->addPerson();

		}
		else if (select == 2)//查看账号
		{
			//cout << "查看账号" << endl;
			man->showPerson();

		}
		else if (select == 3)//查看机房
		{
			//cout << "查看机房" << endl;
			man->showComputer();

		}
		else if (select == 4)//清空预约
		{
			//cout << "清空预约" << endl;
			man->cleanFile();

		}
		else if (select == 0)//注销登录
		{
			delete manager;
			cout << "注销登录成功！" << endl;
			system("pause");
			system("cls");
			return;
		}
		else
		{
			cout << "输入有误，请重新输入！" << endl;
			system("pause");
			system("cls");
		}

	}


}

void studentMenu(Identity*& student)
{
	while (true)
	{
		student->operMenu();
		Student* stu = (Student*)student;
		int select = 0;

		while (!(cin >> select))
		{
			cin.clear();
			while (cin.get() != '\n')
			{
				continue;
			}
			cout << "输入有误，请输入数字！" << endl;
		}

		if (select == 1)
		{
			stu->applyOrder();

		}
		else if (select == 2)
		{
			stu->showMyOrder();

		}
		else if (select == 3)
		{
			stu->showAllOrder();

		}
		else if (select == 4)
		{
			stu->cancelOrder();

		}
		else if (select == 0)
		{
			delete student;
			cout << "注销登录成功！" << endl;
			system("pause");
			system("cls");
			return;

		}
		else
		{
			cout << "输入有误，请重新输入！" << endl;
			system("pause");
			system("cls");
		}
	}

}

void teacherMenu(Identity*& teacher)
{
	while (true)
	{
		teacher->operMenu();
		Teacher* ter = (Teacher*)teacher;
		int select = 0;
		while (!(cin >> select))
		{
			cin.clear();
			while (cin.get() != '\n')
			{
				continue;
			}
			cout << "输入有误，请输入数字！" << endl;
		}

		if (select == 1)
		{
			ter->showAllOrder();

		}
		else if (select == 2)
		{

			ter->validOrder();
		}
		else if (select == 0)
		{
			delete teacher;
			cout << "注销登录成功！" << endl;
			system("pause");
			system("cls");
			return;

		}
		else
		{
			cout << "输入有误，请重新输入！" << endl;
			system("pause");
			system("cls");

		}
	}

}