#include<iostream>
#include<string>
#define MAX 1000
using namespace std;

//�����ϵ�˽ṹ��
struct Person
{
	string m_Name;//����
	int m_Sex;//�Ա�
	int m_Age;//����
	string m_Phone;//�绰
	string m_Addr;//��ַ
};

//���ͨѶ¼�ṹ��
struct Addressbooks
{
	Person personArray[MAX];
	int m_Size;
};

void showMenu();//�˵����溯��
void addPerson(Addressbooks* abs);//�����ϵ�˺���
void showPerson(Addressbooks* abs);//��ʾ��ϵ�˺���
int isExist(Addressbooks* abs, string name);//�����ϵ���Ƿ���ں���
void deletePerson(Addressbooks* abs);//ɾ����ϵ�˺���
void findPerson(Addressbooks* abs);//������ϵ�˺���
void modifyPerson(Addressbooks* abs);//�޸���ϵ�˺���
void cleanPerson(Addressbooks* abs);//���ͨѶ¼����


int main()
{
	Addressbooks abs;//����һ��ͨѶ¼
	abs.m_Size = 0 ;//��ʼ��ͨѶ¼��ϵ�˸���Ϊ0

	int select = 0;
	while (true)
	{
		showMenu();
		cin >> select;
		switch (select)
		{
		case 1://1.�����ϵ��
			addPerson(&abs);
			break;
		case 2://2.��ʾ��ϵ��
			showPerson(&abs);
			break;
		case 3://3.ɾ����ϵ��
			deletePerson(&abs);
			//�������ע�͵��Ĵ����ǲ���isExist������
		/*{
			cout << "��������Ҫɾ������ϵ��������" << endl;
			string name;
			cin >> name;
			if (isExist(&abs, name) == -1)
			{
				cout << "û���ҵ�����ϵ�ˣ�" << endl;
			}
			else
			{
				cout << "�ҵ��˴���ϵ�ˣ�" << endl;
			}
		}*/
			break;
		case 4://4.������ϵ��
			findPerson(&abs);
			break;
		case 5://5.�޸���ϵ��
			modifyPerson(&abs);
			break;
		case 6://6.�����ϵ��
			cleanPerson(&abs);
			break;
		case 0://0.�˳�ͨѶ¼
			cout << "��ӭ�´�ʹ�ã�" << endl;
			system("pause");
			system("cls");
			return 0;
			break;
		default:
			cout << "����������������룡" << endl;
			system("pause");
			system("cls");
			break;
		}
	}

	system("pause");
	return 0;
}

//�˵����溯��
void showMenu()
{
	cout << "************************" << endl;
	cout << "***** 1.�����ϵ�� *****" << endl;
	cout << "***** 2.��ʾ��ϵ�� *****" << endl;
	cout << "***** 3.ɾ����ϵ�� *****" << endl;
	cout << "***** 4.������ϵ�� *****" << endl;
	cout << "***** 5.�޸���ϵ�� *****" << endl;
	cout << "***** 6.�����ϵ�� *****" << endl;
	cout << "***** 0.�˳�ͨѶ¼ *****" << endl;
	cout << "************************" << endl;
}

void addPerson(Addressbooks* abs)//�����ϵ�˺���
{
	if (abs->m_Size >= MAX)
	{
		cout << "ͨѶ¼�������޷���ӣ�" << endl;
		return;
	}
	else
	{
		cout << "��������ϵ��������" << endl;//�����ϵ������
		string name;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;

		cout << "��������ϵ���Ա� " << endl;//�����ϵ���Ա�
		cout << "1---��" << endl;
		cout << "2---Ů" << endl;
		int sex;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			else
			{
				cout << "�����������������룡" << endl;
			}
		}
		
		cout << "��������ϵ�����䣺 " << endl;//�����ϵ������
		int age;
		cin >> age;
		abs->personArray[abs->m_Size].m_Age = age;

		cout << "��������ϵ�˵绰�� " << endl;//�����ϵ�˵绰
		string phone;
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;

		cout << "��������ϵ�˵�ַ�� " << endl;//�����ϵ�˵�ַ
		string address;
		cin >> address;
		abs->personArray[abs->m_Size].m_Addr = address;

		abs->m_Size++;//����ͨѶ¼����
		cout << "��ϲ����ӳɹ�����" << endl;
		system("pause");//�����������
		system("cls");//����
	}
}

void showPerson(Addressbooks* abs)//��ʾ��ϵ�˺���
{
	if (abs->m_Size == 0)//�ж�ͨѶ¼�Ƿ�����
	{
		cout << "��ǰͨѶ¼Ϊ�գ�" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "������ " << abs->personArray[i].m_Name << "\t";//����ˮƽ�Ʊ��ʹ���������ʾ
			cout << "�Ա� " << (abs->personArray[i].m_Sex == 1 ? "��" : "Ů") << "\t";//��1��2��Ӧת��Ϊ���С�����Ů��
			cout << "���䣺 " << abs->personArray[i].m_Age << "\t";
			cout << "�绰�� " << abs->personArray[i].m_Phone << "\t";
			cout << "��ַ�� " << abs->personArray[i].m_Addr << endl;
		}
	}
	system("pause");
	system("cls");
}

int isExist(Addressbooks* abs, string name)//�����ϵ���Ƿ���ں���,������ڣ���ʾ���ڵĵ�ַ����������ڣ���ʾ-1
{
	for (int i = 0; i < abs->m_Size; i++)
	{
		if (abs->personArray[i].m_Name == name)//����ϵ���������м��
		{
			return i;//��⵽��ϵ�ˣ���������ͨѶ¼�ṹ����ϵ�˽ṹ������±�
		}
	}
	return -1;
}

void deletePerson(Addressbooks* abs)//ɾ����ϵ�˺���
{
	cout << "��������Ҫɾ������ϵ�����֣� " << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);//�����ϵ���Ƿ����
	if (ret != -1)
	{//��ϵ�˴��ڣ�ִ��ɾ������
		for (int i = ret; i < abs->m_Size; i++)
		{
			abs->personArray[i] = abs->personArray[i + 1];//�����ڵ���ϵ�˵��±��Ժ����ϵ������ȫ����ǰ�ƶ�
		}
		cout << "ɾ���ɹ���" << endl;
		abs->m_Size--;//������ϵ�˸���
	}
	else
	{
		cout << "���޴��ˣ�" << endl;
	}
	system("pause");
	system("cls");
}

void findPerson(Addressbooks* abs)//������ϵ�˺���
{
	cout << "��������Ҫ���ҵ���ϵ�������� " << endl;
	string name;
	cin >> name;

	int ret = isExist(abs, name);;//�����ϵ���Ƿ����
	if (ret == -1)
	{
		cout << "���޴��ˣ�" << endl;
	}
	else
	{
		cout << "������ " << abs->personArray[ret].m_Name << "\t";//����ˮƽ�Ʊ��ʹ���������ʾ
		cout << "�Ա� " << (abs->personArray[ret].m_Sex == 1 ? "��" : "Ů") << "\t";//��1��2��Ӧת��Ϊ���С�����Ů��
		cout << "���䣺 " << abs->personArray[ret].m_Age << "\t";
		cout << "�绰�� " << abs->personArray[ret].m_Phone << "\t";
		cout << "��ַ�� " << abs->personArray[ret].m_Addr << endl;
	}
	system("pause");
	system("cls");
}

void modifyPerson(Addressbooks* abs)//�޸���ϵ�˺���
{
	cout << "��������Ҫ�޸ĵ���ϵ�������� " << endl;
	string name;
	cin >> name;

	int ret = isExist(abs, name);
	if (ret == -1)
	{
		cout << "���޴��ˣ�" << endl;
	}
	else//ѡ����Ҫ�޸ĵ���Ϣ
	{
		int select1 = 0;
		
		while (true)
		{
			cout << "******************" << endl;
			cout << "*** 1.�޸����� ***" << endl;
			cout << "*** 2.�޸��Ա� ***" << endl;
			cout << "*** 3.�޸����� ***" << endl;
			cout << "*** 4.�޸ĵ绰 ***" << endl;
			cout << "*** 5.�޸ĵ�ַ ***" << endl;
			cout << "*** 6.�˳��޸� ***" << endl;
			cout << "******************" << endl;
			cout << "��������Ҫ�޸ĵ���Ϣ�� " << endl;
			cin >> select1;
			switch (select1)
			{
			case 1://�޸�����
			{
				cout << "��������ϵ��������" << endl;
				string name1;
				cin >> name1;
				abs->personArray[ret].m_Name = name1;
				cout << "�޸ĳɹ���" << endl;
			}
				break;
			case 2://�޸��Ա�
			{
				cout << "��������ϵ���Ա� " << endl;
				cout << "1---��" << endl;
				cout << "2---Ů" << endl;
				int sex;
				while (true)
				{
					cin >> sex;
					if (sex == 1 || sex == 2)
					{
						abs->personArray[ret].m_Sex = sex;
						break;
					}
					else
					{
						cout << "�����������������룡" << endl;
					}
				}
				cout << "�޸ĳɹ���" << endl;
			}
				break;
			case 3://�޸�����
			{
				cout << "��������ϵ�����䣺 " << endl;
				int age;
				cin >> age;
				abs->personArray[ret].m_Age = age;
				cout << "�޸ĳɹ���" << endl;
			}
				break;
			case 4://�޸ĵ绰
			{
				cout << "��������ϵ�˵绰�� " << endl;//�����ϵ�˵绰
				string phone;
				cin >> phone;
				abs->personArray[ret].m_Phone = phone;
				cout << "�޸ĳɹ���" << endl;
			}
				break;
			case 5://�޸ĵ�ַ
			{
				cout << "��������ϵ�˵�ַ�� " << endl;//�����ϵ�˵�ַ
				string address;
				cin >> address;
				abs->personArray[ret].m_Addr = address;
				cout << "�޸ĳɹ���" << endl;
			}
				break;
			case 6:
				system("pause");
				system("cls");
				return;
				break;
			default:
				cout << "�������,���������룡" << endl;
				break;
			}
		}
	}
}

void cleanPerson(Addressbooks* abs)//���ͨѶ¼����
{
	abs->m_Size = 0;//����ϵ�˼�¼��������Ϊ0��ʵ���߼��ϵ����
	cout << "ͨѶ¼����գ�" << endl;
	system("pause");
	system("cls");
}