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

//string GbkToUtf8(const std::string& gbkStr);//����̨���ָ�ʽΪGBK���ĵ��ı����ָ�ʽΪUTF-8����������ͨ���ı��ĵ��ı����ָ�ʽΪGBK���
void LoginIn(string filename, int type);//��¼����--�������ļ������û������
void managerMenu(Identity*& manager);//����Ա�˵�����
void studentMenu(Identity*& student);//ѧ������˵�����
void teacherMenu(Identity*& teacher);//��ʦ�˵�����




int main()
{
	//SetConsoleOutputCP(CP_UTF8);//������̨�����ָ�ʽ��ΪUTF-8
	//SetConsoleCP(CP_UTF8);

	int select = 0;
	while (true)
	{
		cout << "======================  ��ӭ�������ǲ��ͻ���ԤԼϵͳ  ======================" << endl;
		cout << endl << "������������" << endl;
		cout << "\t\t---------------------------------\n";
		cout << "\t\t|                                |\n";
		cout << "\t\t|           1.ѧ������           |\n";
		cout << "\t\t|                                |\n";
		cout << "\t\t|           2.��    ʦ           |\n";
		cout << "\t\t|                                |\n";
		cout << "\t\t|           3.�� �� Ա           |\n";
		cout << "\t\t|                                |\n";
		cout << "\t\t|           0.��    ��           |\n";
		cout << "\t\t|                                |\n";
		cout << "\t\t---------------------------------\n";
		cout << "���������ѡ��";

		while (!(cin >> select))
		{
			cin.clear();
			while (cin.get() != '\n')
			{
				continue;
			}
			cout << "�����������������֣�" << endl;
		}

		switch (select)
		{
		case 1://ѧ������
		{
			LoginIn(STUDENT_FILE, 1);

		}
			break;
		case 2://��ʦ
		{
			LoginIn(TEACHER_FILE, 2);

		}
			break;
		case 3://����Ա
		{
			LoginIn(ADMIN_FILE, 3);

		}
			break;
		case 0://�˳�
		{
			cout << "��ӭ�´�ʹ�ã�" << endl;
			system("pause");
			return 0;
		}
			break;
		default:
		{
			cout << "�����������������룡" << endl;
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
	Identity* person = NULL;//��������ָ��ָ������
	ifstream ifs1;
	ifs1.open(filename, ios::in);
	if (!(ifs1.is_open()))
	{
		cout << "��ʧ�ܣ��ļ������ڣ�" << endl;
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

	int id = 0;
	string name;
	string pwd;

	//ofstream ofs1;
	//ofs1.open("text1.txt", ios::out);
	//ofs1 << "����" << endl;
	//ofs1 << "����" << endl;
	//ofs1 << "����" << endl;
	//ofs1 << "����" << endl;
	//ofs1 << "����" << endl;
	//ofs1 << "���" << endl;
	//ofs1.close();


	if (type == 1)
	{
		cout << "���������ѧ�ţ�" << endl;
		while (!(cin >> id))
		{
			cin.clear();
			while (cin.get() != '\n')
			{
				continue;
			}
			cout << "����������������֣�" << endl;
		}

	}
	else if (type == 2)
	{
		cout << "���������ְ���ţ�" << endl;
		while (!(cin >> id))
		{
			cin.clear();
			while (cin.get() == '\n')
			{
				continue;
			}
			cout << "����������������֣�" << endl;
		}
	}
	cout << "���������������" << endl;
	cin >> name;
	//string name1 = GbkToUtf8(name);//������̨�����GBK��ʽת��Ϊ�ı��ĵ�����ĸ�ʽUTF-8


	cout << "������������룺" << endl;
	cin >> pwd;


	if (type == 1)
	{
		//��֤ѧ����¼
		int fId = 0;
		string fName;
		string fPwd;
		while (ifs1 >> fId && ifs1 >> fName && ifs1 >> fPwd)//�ļ���ȡ���������û�������������Ա�
		{
			//cout << fName << endl;
			if (fId == id && fName == name && fPwd == pwd)
			{
				cout << "ѧ����֤��¼�ɹ���" << endl;	
				system("pause");
				system("cls");
				ifs1.close();
				person = new Student(id, name, pwd);
				//����ѧ������Ӳ˵�
				studentMenu(person);

				return;
			}

		}



	}
	else if (type == 2)
	{
		//��֤��ʦ��¼
		int fId = 0;
		string fName;
		string fPwd;
		while (ifs1 >> fId && ifs1 >> fName && ifs1 >> fPwd)//�ļ���ȡ���������û�������������Ա�
		{
			//cout << fName << endl;
			if (fId == id && fName == name && fPwd == pwd)
			{
				cout << "��ʦ��֤��¼�ɹ���" << endl;				
				system("pause");
				system("cls");
				ifs1.close();
				person = new Teacher(id, name, pwd);
				//������ʦ����Ӳ˵�

				teacherMenu(person);

				return;
			}

		}


	}
	else if(type == 3)
	{
		//��֤����Ա��¼
		string fName;
		string fPwd;
		while (ifs1 >> fName && ifs1 >> fPwd)//�ļ���ȡ���������û�������������Ա�
		{
			//cout << fName << endl;
			if (fName == name && fPwd == pwd)
			{
				cout << "����Ա��֤��¼�ɹ���" << endl;				
				system("pause");
				system("cls");
				ifs1.close();
				person = new Manager(name, pwd);
				//�������Ա����Ӳ˵�
				managerMenu(person);
				
				return;
			}

		}

	}


	cout << "��֤��¼ʧ�ܣ�" << endl;
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
			cout << "�����������������֣�" << endl;
		}

		if (select == 1)//����˺�
		{
			//cout << "����˺�" << endl;
			man->addPerson();

		}
		else if (select == 2)//�鿴�˺�
		{
			//cout << "�鿴�˺�" << endl;
			man->showPerson();

		}
		else if (select == 3)//�鿴����
		{
			//cout << "�鿴����" << endl;
			man->showComputer();

		}
		else if (select == 4)//���ԤԼ
		{
			//cout << "���ԤԼ" << endl;
			man->cleanFile();

		}
		else if (select == 0)//ע����¼
		{
			delete manager;
			cout << "ע����¼�ɹ���" << endl;
			system("pause");
			system("cls");
			return;
		}
		else
		{
			cout << "�����������������룡" << endl;
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
			cout << "�����������������֣�" << endl;
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
			cout << "ע����¼�ɹ���" << endl;
			system("pause");
			system("cls");
			return;

		}
		else
		{
			cout << "�����������������룡" << endl;
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
			cout << "�����������������֣�" << endl;
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
			cout << "ע����¼�ɹ���" << endl;
			system("pause");
			system("cls");
			return;

		}
		else
		{
			cout << "�����������������룡" << endl;
			system("pause");
			system("cls");

		}
	}

}