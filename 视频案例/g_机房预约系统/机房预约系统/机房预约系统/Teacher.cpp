#include"Teacher.h"

Teacher::Teacher()//默认构造函数
{


}


Teacher::Teacher(int empid, string name, string pwd)//有参构造函数---职工编号、姓名、密码
{
	this->m_EmpId = empid;
	this->m_Name = name;
	this->m_Pwd = pwd;

}


void Teacher::operMenu()//菜单界面
{
	cout << "欢迎教师：" << this->m_Name << " 登录！" << endl;
	cout << "\t\t---------------------------------\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|         1.查看所有预约        |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|         2.审核预约            |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|         0.注销登录            |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t---------------------------------\n";
	cout << "请选择你的操作：" << endl;

}


void Teacher::showAllOrder()//查看所有预约
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


void Teacher::validOrder()//审核预约
{
	OrderFile of;

	if (of.m_Size == 0)
	{
		cout << "无预约记录！" << endl;
		system("pause");
		system("cls");
		return;
	}

	vector<int>v;
	int index = 1;
	for (int i = 0; i < of.m_Size; i++)
	{
		if (of.m_orderData[i]["status"] == "1")
		{
			v.push_back(i);
			cout << index++ << "、";
			cout << "预约日期：周" << of.m_orderData[i]["date"];
			cout << "\t时间段：" << ((of.m_orderData[i]["interval"]) == "1" ? "上午" : "下午");
			cout << "\t学号：" << of.m_orderData[i]["stuId"];
			cout << "\t姓名：" << of.m_orderData[i]["stuName"];
			cout << "\t机房号：" << of.m_orderData[i]["roomId"];
			cout << "\t状态：审核中" << endl;

		}
	}


	if (index > 1)
	{
		int select = 0;
		int ret = 0;

		cout << "请选择你要审核的预约编号，0代表返回" << endl;

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
					cout << "请输入审核结果" << endl;
					cout << "1.通过" << endl;
					cout << "2.不通过" << endl;

					while (true)
					{
						while (!(cin >> ret))
						{
							cin.clear();
							while (cin.get() != '\n')
							{
								continue;
							}
							cout << "输入有误，请输入数字！" << endl;
						}

						if (ret == 1)
						{
							of.m_orderData[v[select - 1]]["status"] = "2";
						}
						else if (ret == 2)
						{
							of.m_orderData[v[select - 1]]["status"] = "-1";
						}
						else
						{
							cout << "输入有误，请重新输入！" << endl;
							continue;
						}
						of.updateOrder();
						cout << "审核完毕！" << endl;
						break;
					}

				}


			}
			else
			{
				cout << "输入有误，请重新输入！" << endl;
				continue;
			}
			break;
		}
	}
	else
	{
		cout << "没有待审核的预约！" << endl;
	}
	
	system("pause");
	system("cls");



}