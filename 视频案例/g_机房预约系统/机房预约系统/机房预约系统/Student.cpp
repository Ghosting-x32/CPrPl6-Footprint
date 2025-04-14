#include"Student.h"

Student::Student()//默认构造函数
{



}


Student::Student(int id, string name, string pwd)//有参构造函数----学号、姓名、密码
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_Pwd = pwd;

	this->initvCom();
}


void Student::operMenu()//菜单界面
{
	cout << "欢迎学生代表：" << this->m_Name << " 登录！" << endl;
	cout << "\t\t---------------------------------\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|         1.申请预约            |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|         2.查看我的预约        |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|         3.查看所有预约        |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|         4.取消预约            |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|         0.注销登录            |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t---------------------------------\n";
	cout << "请选择你的操作：" << endl;

}


void Student::applyOrder()//申请预约
{
	cout << "机房开放时间为周一至周五！" << endl;
	cout << "请输入申请预约的时间：" << endl;
	cout << "1.周一" << endl;
	cout << "2.周二" << endl;
	cout << "3.周三" << endl;
	cout << "4.周四" << endl;
	cout << "5.周五" << endl;
	int date = 0;
	int interval = 0;
	int room = 0;

	while (true)
	{
		while (!(cin >> date))
		{
			cin.clear();
			while (cin.get() != '\n')
			{
				continue;
			}
			cout << "输入有误，请输入数字！" << endl;
		}

		if (date >= 1 && date <= 5)
		{
			break;
		}
		else
		{
			cout << "输入有误，请重新输入！" << endl;
		}
	}

	cout << "请输入申请预约的时间段：" << endl;
	cout << "1.上午" << endl;
	cout << "2.下午" << endl;

	while (true)
	{
		while (!(cin >> interval))
		{
			cin.clear();
			while (cin.get() != '\n')
			{
				continue;
			}
			cout << "输入有误，请输入数字！" << endl;
		}

		if (interval == 1 || interval == 2)
		{
			break;
		}
		else
		{
			cout << "输入有误，请重新输入！" << endl;
		}
	}


	cout << "请选择机房：" << endl;
	cout << "1号机房容量：" << this->vCom[0].m_MaxNum << endl;
	cout << "2号机房容量：" << this->vCom[1].m_MaxNum << endl;
	cout << "3号机房容量：" << this->vCom[2].m_MaxNum << endl;

	while (true)
	{
		while (!(cin >> room))
		{
			cin.clear();
			while (cin.get() != '\n')
			{
				continue;
			}
			cout << "输入有误，请输入数字！" << endl;
		}

		if (room == 1 || room == 2 || room == 3)
		{
			break;
		}
		else
		{
			cout << "输入有误，请重新输入！" << endl;
		}
	}

	ofstream ofs1;
	ofs1.open(ORDER_FILE, ios::out | ios::app);
	ofs1 << "date:" << date << " "
		<< "interval:" << interval << " "
		<< "stuId:" << this->m_Id << " "
		<< "stuName:" << this->m_Name << " "
		<< "roomId:" << room << " "
		<< "status:" << 1 << endl;

	ofs1.close();

	system("pause");
	system("cls");


}


void Student::showMyOrder()//查看我的预约
{
	OrderFile of;

	if (of.m_Size == 0)
	{
		cout << "无预约记录！" << endl;
		system("pause");
		system("cls");
		return;
	}

	int index = 1;
	for (int i = 0; i < of.m_Size; i++)
	{
		//string转int
		//string 利用.c_str()转const char*
		//利用atoi(const char*) 转int
		if (this->m_Id == atoi(of.m_orderData[i]["stuId"].c_str()))
		{
			cout << index++ << "、";
			cout << "预约日期：周" << of.m_orderData[i]["date"];
			cout << "\t时间段：" << ((of.m_orderData[i]["interval"]) == "1" ? "上午" : "下午");
			cout << "\t机房号：" << of.m_orderData[i]["roomId"];

			string status = "\t状态：";
			if (of.m_orderData[i]["status"] == "1")
			{
				status += "审核中";
			}
			else if (of.m_orderData[i]["status"] == "2")
			{
				status += "预约成功";
			}
			else if (of.m_orderData[i]["status"] == "-1")
			{
				status += "预约失败，审核未通过";
			}
			else
			{
				status += "预约已取消";
			}
			cout << status << endl;
		}
	}
	system("pause");
	system("cls");


}


void Student::showAllOrder()//查看所有预约
{
	OrderFile of;

	if (of.m_Size == 0)
	{
		cout << "无预约记录！" << endl;
		system("pause");
		system("cls");
		return;
	}

	for (int i = 0; i < of.m_Size; i++)
	{	
		cout << i + 1 << "、";
		cout << "预约日期：周" << of.m_orderData[i]["date"];
		cout << "\t时间段：" << ((of.m_orderData[i]["interval"]) == "1" ? "上午" : "下午");
		cout << "\t学号：" << of.m_orderData[i]["stuId"];
		cout << "\t姓名：" << of.m_orderData[i]["stuName"];
		cout << "\t机房号：" << of.m_orderData[i]["roomId"];

		string status = "\t状态：";
		if (of.m_orderData[i]["status"] == "1")
		{
			status += "审核中";
		}
		else if (of.m_orderData[i]["status"] == "2")
		{
			status += "预约成功";
		}
		else if (of.m_orderData[i]["status"] == "-1")
		{
			status += "预约失败，审核未通过";
		}
		else
		{
			status += "预约已取消";
		}
		cout << status << endl;

	}
	system("pause");
	system("cls");



}
void Student::cancelOrder()//取消预约
{
	OrderFile of;

	if (of.m_Size == 0)
	{
		cout << "无预约记录！" << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "审核中或预约成功的记录可以取消，请输入取消的记录" << endl;
	vector<int>v;
	int index = 1;
	for (int i = 0; i < of.m_Size; i++)
	{
		if (this->m_Id == atoi(of.m_orderData[i]["stuId"].c_str()))
		{
			cout << "测试" << endl;
			if (of.m_orderData[i]["status"] == "1" || of.m_orderData[i]["status"] == "2")
			{
				v.push_back(i);
				cout << index++ << "、";
				cout << "预约日期：周" << of.m_orderData[i]["date"];
				cout << "\t时间段：" << ((of.m_orderData[i]["interval"]) == "1" ? "上午" : "下午");
				cout << "\t机房号：" << of.m_orderData[i]["roomId"];

				string status = "\t状态：";
				if (of.m_orderData[i]["status"] == "1")
				{
					status += "审核中";
				}
				else if (of.m_orderData[i]["status"] == "2")
				{
					status += "预约成功";
				}
				cout << status << endl;

			}

		}


	}

	cout << "请输入取消的记录，0代表返回" << endl;

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

		if (select >= 0 && select <= of.m_Size)
		{
			if (select == 0)
			{
				break;
			}
			else
			{
				of.m_orderData[v[select - 1]]["status"] = "0";
				of.updateOrder();
				cout << "已取消预约" << endl;
				break;
			}


		}
		else
		{
			cout << "输入有误，请重新输入！" << endl;
		}

	}

	system("pause");
	system("cls");



}

void Student::initvCom()
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