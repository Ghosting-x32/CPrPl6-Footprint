#include"Teacher.h"

Teacher::Teacher()//Ĭ�Ϲ��캯��
{


}


Teacher::Teacher(int empid, string name, string pwd)//�вι��캯��---ְ����š�����������
{
	this->m_EmpId = empid;
	this->m_Name = name;
	this->m_Pwd = pwd;

}


void Teacher::operMenu()//�˵�����
{
	cout << "��ӭ��ʦ��" << this->m_Name << " ��¼��" << endl;
	cout << "\t\t---------------------------------\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|         1.�鿴����ԤԼ        |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|         2.���ԤԼ            |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|         0.ע����¼            |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t---------------------------------\n";
	cout << "��ѡ����Ĳ�����" << endl;

}


void Teacher::showAllOrder()//�鿴����ԤԼ
{
	OrderFile of;

	if (of.m_Size == 0)
	{
		cout << "��ԤԼ��¼��" << endl;
		system("pause");
		system("cls");
		return;
	}

	for (int i = 0; i < of.m_Size; i++)
	{
		cout << i + 1 << "��";
		cout << "ԤԼ���ڣ���" << of.m_orderData[i]["date"];
		cout << "\tʱ��Σ�" << ((of.m_orderData[i]["interval"]) == "1" ? "����" : "����");
		cout << "\tѧ�ţ�" << of.m_orderData[i]["stuId"];
		cout << "\t������" << of.m_orderData[i]["stuName"];
		cout << "\t�����ţ�" << of.m_orderData[i]["roomId"];

		string status = "\t״̬��";
		if (of.m_orderData[i]["status"] == "1")
		{
			status += "�����";
		}
		else if (of.m_orderData[i]["status"] == "2")
		{
			status += "ԤԼ�ɹ�";
		}
		else if (of.m_orderData[i]["status"] == "-1")
		{
			status += "ԤԼʧ�ܣ����δͨ��";
		}
		else
		{
			status += "ԤԼ��ȡ��";
		}
		cout << status << endl;

	}
	system("pause");
	system("cls");


}


void Teacher::validOrder()//���ԤԼ
{
	OrderFile of;

	if (of.m_Size == 0)
	{
		cout << "��ԤԼ��¼��" << endl;
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
			cout << index++ << "��";
			cout << "ԤԼ���ڣ���" << of.m_orderData[i]["date"];
			cout << "\tʱ��Σ�" << ((of.m_orderData[i]["interval"]) == "1" ? "����" : "����");
			cout << "\tѧ�ţ�" << of.m_orderData[i]["stuId"];
			cout << "\t������" << of.m_orderData[i]["stuName"];
			cout << "\t�����ţ�" << of.m_orderData[i]["roomId"];
			cout << "\t״̬�������" << endl;

		}
	}


	if (index > 1)
	{
		int select = 0;
		int ret = 0;

		cout << "��ѡ����Ҫ��˵�ԤԼ��ţ�0������" << endl;

		while (true)
		{
			while (!(cin >> select))
			{
				cin.clear();
				while (cin.get() != '\n')
				{
					continue;
				}
				cout << "�����������������֣�" << endl;
			}
			if (select >= 0 && select <= of.m_Size)
			{
				if (select == 0)
				{
					break;
				}
				else
				{
					cout << "��������˽��" << endl;
					cout << "1.ͨ��" << endl;
					cout << "2.��ͨ��" << endl;

					while (true)
					{
						while (!(cin >> ret))
						{
							cin.clear();
							while (cin.get() != '\n')
							{
								continue;
							}
							cout << "�����������������֣�" << endl;
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
							cout << "�����������������룡" << endl;
							continue;
						}
						of.updateOrder();
						cout << "�����ϣ�" << endl;
						break;
					}

				}


			}
			else
			{
				cout << "�����������������룡" << endl;
				continue;
			}
			break;
		}
	}
	else
	{
		cout << "û�д���˵�ԤԼ��" << endl;
	}
	
	system("pause");
	system("cls");



}