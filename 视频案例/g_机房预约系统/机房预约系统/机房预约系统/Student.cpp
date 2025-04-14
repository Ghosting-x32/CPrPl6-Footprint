#include"Student.h"

Student::Student()//Ĭ�Ϲ��캯��
{



}


Student::Student(int id, string name, string pwd)//�вι��캯��----ѧ�š�����������
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_Pwd = pwd;

	this->initvCom();
}


void Student::operMenu()//�˵�����
{
	cout << "��ӭѧ������" << this->m_Name << " ��¼��" << endl;
	cout << "\t\t---------------------------------\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|         1.����ԤԼ            |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|         2.�鿴�ҵ�ԤԼ        |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|         3.�鿴����ԤԼ        |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|         4.ȡ��ԤԼ            |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|         0.ע����¼            |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t---------------------------------\n";
	cout << "��ѡ����Ĳ�����" << endl;

}


void Student::applyOrder()//����ԤԼ
{
	cout << "��������ʱ��Ϊ��һ�����壡" << endl;
	cout << "����������ԤԼ��ʱ�䣺" << endl;
	cout << "1.��һ" << endl;
	cout << "2.�ܶ�" << endl;
	cout << "3.����" << endl;
	cout << "4.����" << endl;
	cout << "5.����" << endl;
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
			cout << "�����������������֣�" << endl;
		}

		if (date >= 1 && date <= 5)
		{
			break;
		}
		else
		{
			cout << "�����������������룡" << endl;
		}
	}

	cout << "����������ԤԼ��ʱ��Σ�" << endl;
	cout << "1.����" << endl;
	cout << "2.����" << endl;

	while (true)
	{
		while (!(cin >> interval))
		{
			cin.clear();
			while (cin.get() != '\n')
			{
				continue;
			}
			cout << "�����������������֣�" << endl;
		}

		if (interval == 1 || interval == 2)
		{
			break;
		}
		else
		{
			cout << "�����������������룡" << endl;
		}
	}


	cout << "��ѡ�������" << endl;
	cout << "1�Ż���������" << this->vCom[0].m_MaxNum << endl;
	cout << "2�Ż���������" << this->vCom[1].m_MaxNum << endl;
	cout << "3�Ż���������" << this->vCom[2].m_MaxNum << endl;

	while (true)
	{
		while (!(cin >> room))
		{
			cin.clear();
			while (cin.get() != '\n')
			{
				continue;
			}
			cout << "�����������������֣�" << endl;
		}

		if (room == 1 || room == 2 || room == 3)
		{
			break;
		}
		else
		{
			cout << "�����������������룡" << endl;
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


void Student::showMyOrder()//�鿴�ҵ�ԤԼ
{
	OrderFile of;

	if (of.m_Size == 0)
	{
		cout << "��ԤԼ��¼��" << endl;
		system("pause");
		system("cls");
		return;
	}

	int index = 1;
	for (int i = 0; i < of.m_Size; i++)
	{
		//stringתint
		//string ����.c_str()תconst char*
		//����atoi(const char*) תint
		if (this->m_Id == atoi(of.m_orderData[i]["stuId"].c_str()))
		{
			cout << index++ << "��";
			cout << "ԤԼ���ڣ���" << of.m_orderData[i]["date"];
			cout << "\tʱ��Σ�" << ((of.m_orderData[i]["interval"]) == "1" ? "����" : "����");
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
	}
	system("pause");
	system("cls");


}


void Student::showAllOrder()//�鿴����ԤԼ
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
void Student::cancelOrder()//ȡ��ԤԼ
{
	OrderFile of;

	if (of.m_Size == 0)
	{
		cout << "��ԤԼ��¼��" << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "����л�ԤԼ�ɹ��ļ�¼����ȡ����������ȡ���ļ�¼" << endl;
	vector<int>v;
	int index = 1;
	for (int i = 0; i < of.m_Size; i++)
	{
		if (this->m_Id == atoi(of.m_orderData[i]["stuId"].c_str()))
		{
			cout << "����" << endl;
			if (of.m_orderData[i]["status"] == "1" || of.m_orderData[i]["status"] == "2")
			{
				v.push_back(i);
				cout << index++ << "��";
				cout << "ԤԼ���ڣ���" << of.m_orderData[i]["date"];
				cout << "\tʱ��Σ�" << ((of.m_orderData[i]["interval"]) == "1" ? "����" : "����");
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
				cout << status << endl;

			}

		}


	}

	cout << "������ȡ���ļ�¼��0������" << endl;

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
				of.m_orderData[v[select - 1]]["status"] = "0";
				of.updateOrder();
				cout << "��ȡ��ԤԼ" << endl;
				break;
			}


		}
		else
		{
			cout << "�����������������룡" << endl;
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
		cout << "�ļ���ʧ�ܣ�" << endl;
		ifs1.close();
		system("pause");
		system("cls");
		return;
	}

	char ch;
	ifs1 >> ch;
	if (ifs1.eof())
	{
		cout << "�ļ�����Ϊ�գ�" << endl;
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
	cout << "��ǰ��������Ϊ��" << vCom.size() << endl;
	ifs1.close();

}