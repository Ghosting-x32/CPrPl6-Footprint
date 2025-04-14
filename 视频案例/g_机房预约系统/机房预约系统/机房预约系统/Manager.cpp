#include"Manager.h"

Manager::Manager()//默认构造函数
{


}


Manager::Manager(string name, string pwd)//有参构造函数---姓名、密码
{
	this->m_Name = name;
	this->m_Pwd = pwd;

	this->initVector();
	this->initvCom();
}


void Manager::operMenu()//菜单界面
{

	cout << "欢迎管理员：" << this->m_Name << " 登录！" << endl;
	cout << "\t\t---------------------------------\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|         1.添加账号            |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|         2.查看账号            |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|         3.查看机房            |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|         4.清空预约            |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|         0.注销登录            |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t---------------------------------\n";
	cout << "请选择你的操作：" << endl;

}


void Manager::addPerson()//添加账号
{
	cout << "请输入添加账号的类型" << endl;
	cout << "1.添加学生" << endl;
	cout << "2.添加老师" << endl;

	string fileName;
	string tip;
	string errorTip;
	ofstream ofs1;
	//ifstream ifs1;

	int select = 0;
	while (true)
	{
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
			fileName = STUDENT_FILE;
			tip = "请输入学号：";
			errorTip = "你输入的学号已被使用，请重新输入！";
			break;
		}
		else if (select == 2)
		{
			fileName = TEACHER_FILE;
			tip = "请输入职工编号：";
			errorTip = "你输入的职工编号已被使用，请重新输入！";
			break;
		}
		else
		{
			cout << "输入有误，请重新输入！" << endl;
		}
	}

	ofs1.open(fileName, ios::out | ios::app);
	int id = 0;
	string name;
	string pwd;

	//int fileId = 0;
	//string fileName_1;
	//string filePwd;
	//int index = 0;



	while (true)//检验输入的ID号不重复（确认ID没有被使用）
	{
		cout << tip << endl;

		while (!(cin >> id))
		{
			cin.clear();
			while (cin.get() != '\n')
			{
				continue;
			}
			cout << "输入有误，请输入数字！" << endl;
		}

		bool ret = this->checkRepeat(id, select);

		if (ret == true)
		{
			cout << errorTip << endl;
		}
		else
		{
			break;
		}
	}

	//while (true)//检验输入的ID号不重复（确认ID没有被使用）//自己的方法实现不出来
	//{
	//	cout << tip << endl;

	//	while (!(cin >> id))
	//	{
	//		cin.clear();
	//		while (cin.get() == '\n')
	//		{
	//			continue;
	//		}
	//		cout << "输入有误，请输入数字！" << endl;
	//	}

	//	cin.clear();
	//	ifs1.clear();
	//	ifs1.open(fileName, ios::in);

	//	while (ifs1 >> fileId)
	//	{
	//		if (fileId == id)
	//		{
	//			index++;
	//		}
	//	}
	//	
	//	cout << index << endl;
	//	if (index != 0)
	//	{
	//		cout << "你输入的ID已被使用，请重新输入！" << endl;
	//	}
	//	else
	//	{
	//		ifs1.close();
	//		break;
	//	}
	//}

	cout << "请输入姓名：" << endl;
	cin >> name;

	cout << "请输入密码：" << endl;
	cin >> pwd;



	ofs1 << id << " " << name << " " << pwd << endl;
	cout << "添加成功！" << endl;
	system("pause");
	system("cls");
	ofs1.close();
	this->initVector();

}

void printStudent(const Student& s)
{
	cout << "学号： " << s.m_Id << "\t姓名：" << s.m_Name << "\t密码：" << s.m_Pwd << endl;
}

void printTeacher(const Teacher& t)
{
	cout << "职工编号： " << t.m_EmpId << "\t姓名：" << t.m_Name << "\t密码：" << t.m_Pwd << endl;
}


void Manager::showPerson()//查看账号
{
	cout << "请选择查看内容：" << endl;
	cout << "1.查看所有学生" << endl;
	cout << "2.查看所有老师" << endl;
	int select = 0;
	while (true)
	{
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
			cout << "所有学生信息如下：" << endl;
			for_each(vStu.begin(), vStu.end(), printStudent);
			break;
		}
		else if (select == 2)
		{
			cout << "所有老师信息如下：" << endl;
			for_each(vTea.begin(), vTea.end(), printTeacher);
			break;
		}
		else
		{
			cout << "输入有误，请重新输入！" << endl;
		}
	}
	system("pause");
	system("cls");
}

void printComputerRoom(const ComputerRoom& com)
{
	cout << "机房编号：" << com.m_ComId << "\t机房最大容量：" << com.m_MaxNum << endl;
}

void Manager::showComputer()//查看机房信息
{
	cout << "机房信息如下：" << endl;
	for_each(vCom.begin(), vCom.end(), printComputerRoom);
	system("pause");
	system("cls");
}


void Manager::cleanFile()//清空预约记录
{
	ofstream ofs1;
	ofs1.open(ORDER_FILE, ios::trunc);
	ofs1.close();
	cout << "清空成功！" << endl;
	system("pause");
	system("cls");
}


void Manager::initVector()
{
	ifstream ifs1;
	ifs1.open(STUDENT_FILE, ios::in);
	if (!(ifs1.is_open()))
	{
		cout << "文件打开失败！" << endl;
		system("pause");
		system("cls");
		ifs1.close();
		return;
	}

	char ch;
	ifs1 >> ch;
	if (ifs1.eof())
	{
		cout << "文件数据为空！" << endl;
		system("pause");
		system("cls");
		ifs1.close();
		return;
	}
	ifs1.putback(ch);

	vStu.clear();
	vTea.clear();

	Student s;
	while (ifs1 >> s.m_Id && ifs1 >> s.m_Name && ifs1 >> s.m_Pwd)
	{
		vStu.push_back(s);
	}
	cout << "当前学生数量为：" << vStu.size() << endl;
	ifs1.close();

	ifs1.open(TEACHER_FILE, ios::in);
	if (!(ifs1.is_open()))
	{
		cout << "文件打开失败！" << endl;
		system("pause");
		system("cls");
		ifs1.close();
		return;
	}

	char ch1;
	ifs1 >> ch1;
	if (ifs1.eof())
	{
		cout << "文件数据为空！" << endl;
		ifs1.close();
		system("pause");
		system("cls");
		return;
	}
	ifs1.putback(ch1);

	Teacher t;
	while (ifs1 >> t.m_EmpId && ifs1 >> t.m_Name && ifs1 >> t.m_Pwd)
	{
		vTea.push_back(t);
	}
	cout << "当前老师数量为：" << vTea.size() << endl;
	ifs1.close();

}

bool Manager::checkRepeat(int id, int type)
{
	if (type == 1)
	{
		for (vector<Student>::iterator it = vStu.begin(); it != vStu.end(); it++)
		{
			if (id == it->m_Id)
			{
				return true;
			}
		}
	}
	else if (type == 2)
	{
		for (vector<Teacher>::iterator it = vTea.begin(); it != vTea.end(); it++)
		{
			if (id == it->m_EmpId)
			{
				return true;
			}
		}
	}
	return false;

}

void Manager::initvCom()
{
	ifstream ifs1;
	ifs1.open(COMPUTER_FILE, ios::in);
	if (!(ifs1.is_open()))
	{
		cout << "文件打开失败！" << endl;
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


	ComputerRoom c;
	while (ifs1 >> c.m_ComId && ifs1 >> c.m_MaxNum)
	{
		vCom.push_back(c);
	}
	cout << "当前机房数量为：" << vCom.size() << endl;
	ifs1.close();

}
