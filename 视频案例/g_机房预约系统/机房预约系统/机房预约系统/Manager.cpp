#include"Manager.h"

Manager::Manager()//Ĭ�Ϲ��캯��
{


}


Manager::Manager(string name, string pwd)//�вι��캯��---����������
{
	this->m_Name = name;
	this->m_Pwd = pwd;

	this->initVector();
	this->initvCom();
}


void Manager::operMenu()//�˵�����
{

	cout << "��ӭ����Ա��" << this->m_Name << " ��¼��" << endl;
	cout << "\t\t---------------------------------\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|         1.����˺�            |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|         2.�鿴�˺�            |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|         3.�鿴����            |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|         4.���ԤԼ            |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|         0.ע����¼            |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t---------------------------------\n";
	cout << "��ѡ����Ĳ�����" << endl;

}


void Manager::addPerson()//����˺�
{
	cout << "����������˺ŵ�����" << endl;
	cout << "1.���ѧ��" << endl;
	cout << "2.�����ʦ" << endl;

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
			cout << "�����������������֣�" << endl;
		}

		if (select == 1)
		{
			fileName = STUDENT_FILE;
			tip = "������ѧ�ţ�";
			errorTip = "�������ѧ���ѱ�ʹ�ã����������룡";
			break;
		}
		else if (select == 2)
		{
			fileName = TEACHER_FILE;
			tip = "������ְ����ţ�";
			errorTip = "�������ְ������ѱ�ʹ�ã����������룡";
			break;
		}
		else
		{
			cout << "�����������������룡" << endl;
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



	while (true)//���������ID�Ų��ظ���ȷ��IDû�б�ʹ�ã�
	{
		cout << tip << endl;

		while (!(cin >> id))
		{
			cin.clear();
			while (cin.get() != '\n')
			{
				continue;
			}
			cout << "�����������������֣�" << endl;
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

	//while (true)//���������ID�Ų��ظ���ȷ��IDû�б�ʹ�ã�//�Լ��ķ���ʵ�ֲ�����
	//{
	//	cout << tip << endl;

	//	while (!(cin >> id))
	//	{
	//		cin.clear();
	//		while (cin.get() == '\n')
	//		{
	//			continue;
	//		}
	//		cout << "�����������������֣�" << endl;
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
	//		cout << "�������ID�ѱ�ʹ�ã����������룡" << endl;
	//	}
	//	else
	//	{
	//		ifs1.close();
	//		break;
	//	}
	//}

	cout << "������������" << endl;
	cin >> name;

	cout << "���������룺" << endl;
	cin >> pwd;



	ofs1 << id << " " << name << " " << pwd << endl;
	cout << "��ӳɹ���" << endl;
	system("pause");
	system("cls");
	ofs1.close();
	this->initVector();

}

void printStudent(const Student& s)
{
	cout << "ѧ�ţ� " << s.m_Id << "\t������" << s.m_Name << "\t���룺" << s.m_Pwd << endl;
}

void printTeacher(const Teacher& t)
{
	cout << "ְ����ţ� " << t.m_EmpId << "\t������" << t.m_Name << "\t���룺" << t.m_Pwd << endl;
}


void Manager::showPerson()//�鿴�˺�
{
	cout << "��ѡ��鿴���ݣ�" << endl;
	cout << "1.�鿴����ѧ��" << endl;
	cout << "2.�鿴������ʦ" << endl;
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

		if (select == 1)
		{
			cout << "����ѧ����Ϣ���£�" << endl;
			for_each(vStu.begin(), vStu.end(), printStudent);
			break;
		}
		else if (select == 2)
		{
			cout << "������ʦ��Ϣ���£�" << endl;
			for_each(vTea.begin(), vTea.end(), printTeacher);
			break;
		}
		else
		{
			cout << "�����������������룡" << endl;
		}
	}
	system("pause");
	system("cls");
}

void printComputerRoom(const ComputerRoom& com)
{
	cout << "������ţ�" << com.m_ComId << "\t�������������" << com.m_MaxNum << endl;
}

void Manager::showComputer()//�鿴������Ϣ
{
	cout << "������Ϣ���£�" << endl;
	for_each(vCom.begin(), vCom.end(), printComputerRoom);
	system("pause");
	system("cls");
}


void Manager::cleanFile()//���ԤԼ��¼
{
	ofstream ofs1;
	ofs1.open(ORDER_FILE, ios::trunc);
	ofs1.close();
	cout << "��ճɹ���" << endl;
	system("pause");
	system("cls");
}


void Manager::initVector()
{
	ifstream ifs1;
	ifs1.open(STUDENT_FILE, ios::in);
	if (!(ifs1.is_open()))
	{
		cout << "�ļ���ʧ�ܣ�" << endl;
		system("pause");
		system("cls");
		ifs1.close();
		return;
	}

	char ch;
	ifs1 >> ch;
	if (ifs1.eof())
	{
		cout << "�ļ�����Ϊ�գ�" << endl;
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
	cout << "��ǰѧ������Ϊ��" << vStu.size() << endl;
	ifs1.close();

	ifs1.open(TEACHER_FILE, ios::in);
	if (!(ifs1.is_open()))
	{
		cout << "�ļ���ʧ�ܣ�" << endl;
		system("pause");
		system("cls");
		ifs1.close();
		return;
	}

	char ch1;
	ifs1 >> ch1;
	if (ifs1.eof())
	{
		cout << "�ļ�����Ϊ�գ�" << endl;
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
	cout << "��ǰ��ʦ����Ϊ��" << vTea.size() << endl;
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
