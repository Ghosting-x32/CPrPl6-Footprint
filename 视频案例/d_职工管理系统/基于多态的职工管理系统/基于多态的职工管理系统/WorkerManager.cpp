#include"WorkerManager.h"

WorkerManager::WorkerManager()
{
	//1.�ļ������ڵ������ʼ��
	ifstream ifs1;
	ifs1.open(FILENAME, ios::in);

	if (!ifs1.is_open())
	{
		cout << "�ļ������ڣ�" << endl;
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs1.close();
		return;
	}
	//2.�ļ����ڣ�������Ϊ��
	char ch;
	ifs1 >> ch;
	if (ifs1.eof())
	{
		cout << "�ļ�����Ϊ�գ�" << endl;
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs1.close();
		return;
	}
	//3.�ļ����ڣ���������
	int num = this->get_EmpNum();
	cout << "ְ������Ϊ��" << num << endl;
	this->m_EmpNum = num;

	this->m_FileIsEmpty = false;

	this->m_EmpArray = new Worker * [this->m_EmpNum];
	this->init_Emp();	
	//����Ϊ���Գ�ʼ��m_EmpArray�Ĵ���
	//for (int i = 0; i < this->m_EmpNum; i++)
	//{
	//	cout << "ְ�����: " << this->m_EmpArray[i]->m_Id
	//		<< "\tְ������: " << this->m_EmpArray[i]->m_Name
	//		<< "\t��λ: " << this->m_EmpArray[i]->m_DeptId << endl;
	//}
}

WorkerManager::~WorkerManager()
{
	if (this->m_EmpArray != NULL)
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			if (this->m_EmpArray[i] != NULL)
			{
				delete this->m_EmpArray[i];
				this->m_EmpArray[i] = NULL;
			}			
		}
		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
	}
}


void WorkerManager::ShowMenu()
{
	cout << "******************************************" << endl;
	cout << "********* ��ӭʹ��ְ������ϵͳ�� *********" << endl;
	cout << "************ 0.�˳�������� **************" << endl;
	cout << "************ 1.����ְ����Ϣ **************" << endl;
	cout << "************ 2.��ʾְ����Ϣ **************" << endl;
	cout << "************ 3.ɾ����ְְ�� **************" << endl;
	cout << "************ 4.�޸�ְ����Ϣ **************" << endl;
	cout << "************ 5.����ְ����Ϣ **************" << endl;
	cout << "************ 6.���ձ������ **************" << endl;
	cout << "************ 7.��������ĵ� **************" << endl;
	cout << "******************************************" << endl;
}

void WorkerManager::ExitSystem()
{
	system("cls");
	cout << "��ӭ�´�ʹ�ã�" << endl;
	system("pause");
	exit(0);
}

int WorkerManager::get_EmpNum()
{
	ifstream ifs1;
	ifs1.open(FILENAME, ios::in);

	int id;
	string name;
	int deptid;

	int num = 0;

	while (ifs1 >> id && ifs1 >> name && ifs1 >> deptid)
	{
		num++;
	}
	return num;
}

void WorkerManager::init_Emp()
{
	ifstream ifs1;
	ifs1.open(FILENAME, ios::in);

	int id;
	string name;
	int deptid;

	int index = 0;

	while (ifs1 >> id && ifs1 >> name && ifs1 >> deptid)
	{
		Worker* worker = NULL;
		if (deptid == 1)
		{
			worker = new Employee(id, name, deptid);
		}
		else if (deptid == 2)
		{
			worker = new Manager(id, name, deptid);
		}
		else if (deptid == 3)
		{
			worker = new Boss(id, name, deptid);
		}
		this->m_EmpArray[index] = worker;
		index++;
	}
	ifs1.close();
}

void WorkerManager::Save()
{
	ofstream ofs1;
	ofs1.open(FILENAME, ios::out);

	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs1 << this->m_EmpArray[i]->m_Id << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_DeptId << endl;
	}
	ofs1.close();
}

void WorkerManager::Del_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ�û�����ݣ�" << endl;
	}
	else
	{
		cout << "��������Ҫɾ����ְ����ţ�" << endl;
		int id;
		while (!(cin >> id))
		{
			cin.clear();
			while (cin.get() == '\n')
			{
				continue;
			}
			cout << "����ʧ�ܣ����������֣�" << endl;
		}

		int index = this->IsExist(id);
		if (index == -1)
		{
			cout << "ɾ��ʧ�ܣ�û���ҵ���ְ����" << endl;
		}
		else
		{
			for (int i = index; i < this->m_EmpNum - 1; i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_EmpNum--;
			cout << "ɾ���ɹ���" << endl;
			this->Save();
		}
	}
	system("pause");
	system("cls");
}

void WorkerManager::Clean_File()
{
	cout << "ȷ����գ�" << endl;
	cout << "1.ȷ��" << endl;
	cout << "2.����" << endl;
	int select = 0;
	while (true)
	{
		while (!(cin >> select))
		{
			cin.clear();
			while (cin.get() == '\n')
			{
				continue;
			}
			cout << "����ʧ�ܣ����������֣�" << endl;
		}
		if (select == 1)
		{
			ofstream ofs1;
			ofs1.open(FILENAME, ios::trunc);//����ļ��Ѵ��ڣ�ɾ���ļ���������

			if (this->m_EmpArray != NULL)
			{
				for (int i = 0; i < this->m_EmpNum; i++)
				{
					if (this->m_EmpArray[i] != NULL)
					{
						delete this->m_EmpArray[i];
						this->m_EmpArray[i] = NULL;
					}
				}
				delete[] this->m_EmpArray;
				this->m_EmpArray = NULL;
				this->m_EmpNum = 0;
				this->m_FileIsEmpty = true;
			}
			cout << "���������ɣ�" << endl;
			break;
		}
		else if(select == 2)
		{
			cout << "���ݱ����ɹ���û����գ�" << endl;
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

void WorkerManager::Mod_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ�û�����ݣ�" << endl;
	}
	else
	{
		cout << "��������Ҫ�޸ĵ�ְ����ţ�" << endl;
		int id;
		while (!(cin >> id))
		{
			cin.clear();
			while (cin.get() == '\n')
			{
				continue;
			}
			cout << "����ʧ�ܣ����������֣�" << endl;
		}

		int index = this->IsExist(id);
		if (index == -1)
		{
			cout << "�޸�ʧ�ܣ����޴��ˣ�" << endl;		
		}
		else
		{
			cout << "�鵽���Ϊ " << id << " ��ְ����" << endl;
			cout << "**********************" << endl;
			cout << "*** 1.�޸�ְ����� ***" << endl;
			cout << "*** 2.�޸�ְ������ ***" << endl;
			cout << "*** 3.�޸�ְ����λ ***" << endl;
			cout << "**********************" << endl;
			cout << "��ѡ����Ҫ�޸ĵ���Ŀ��" << endl;
			int select1;
			while (true)
			{
				while (!(cin >> select1))
				{
					cin.clear();
					while (cin.get() == '\n')
					{
						continue;
					}
					cout << "����ʧ�ܣ����������֣�" << endl;
				}
				if (select1 == 1)
				{
					cout << "��������ְ����ţ�" << endl;
					int id1 = 0;
					while (true)//����ְ������Ƿ�ʹ��
					{
						while (!(cin >> id1))//�������벻Ϊ�������͵������ַ�������������
						{
							cin.clear();
							while (cin.get() != '\n')
								continue;
							cout << "����������������֣�" << endl;
						}

						int temp = 0;
						for (int i = 0; i < this->m_EmpNum; i++)
						{

							if (id1 == this->m_EmpArray[i]->m_Id)
							{
								temp++;
							}
						}

						if (temp > 0)
						{
							cout << "ְ������ѱ�ʹ�ã�����������ְ����ţ�" << endl;
							continue;
						}
						else
						{
							cout << "ְ�������Ч��" << endl;
							break;
						}
					}
					this->m_EmpArray[index]->m_Id = id1;
					this->Save();
					break;
				}
				else if (select1 == 2)
				{
					cout << "�������µ�ְ��������" << endl;
					string name;
					cin >> name;
					this->m_EmpArray[index]->m_Name = name;
					this->Save();
					break;
				}
				else if (select1 == 3)
				{
					cout << "��ѡ���µ�ְ����λ��" << endl;
					cout << "1.��ͨԱ��" << endl;
					cout << "2.����" << endl;
					cout << "3.�ܲ�" << endl;
					int select2 = 0;
					while (true)
					{
						while (!(cin >> select2))//�������벻Ϊ�������͵������ַ�������������
						{
							cin.clear();
							while (cin.get() != '\n')
								continue;
							cout << "����������������֣�" << endl;
						}
						if (select2 == 1 || select2 == 2 || select2 == 3)
						{
							this->m_EmpArray[index]->m_DeptId = select2;
							this->Save();
							break;
						}					
						else
						{
							cout << "����������������룡" << endl;
							continue;
						}
					}
					break;
				}
				else
				{
					cout << "�����������������룡" << endl;
				}
			}
		}
	}
	system("pause");
	system("cls");
}

void WorkerManager::Show_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ�û�����ݣ�" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			this->m_EmpArray[i]->ShowInfo();
		}
	}
	system("pause");
	system("cls");
}

void WorkerManager::Sort_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ�û�����ݣ�" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "��ѡ���������ʽ��" << endl;
		cout << "1.����ְ����Ž�����������" << endl;
		cout << "2.����ְ����Ž��н�������" << endl;
		int select = 0;

		flag:
		while (true)
		{
			while (!(cin >> select))
			{
				cin.clear();
				while (cin.get() == '\n')
				{
					continue;
				}
				cout << "�����������������֣�" << endl;
			}
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				int minorMax = i;
				for (int j = i + 1; j < this->m_EmpNum; j++)
				{
					if (select == 1)
					{
						if (this->m_EmpArray[minorMax]->m_Id > this->m_EmpArray[j]->m_Id)
						{
							minorMax = j;
						}

					}
					else if (select == 2)
					{
						if (this->m_EmpArray[minorMax]->m_Id < this->m_EmpArray[j]->m_Id)
						{
							minorMax = j;
						}
					}
					else
					{
						cout << "�����������������룡" << endl;
						goto flag;
					}
				}
				if (minorMax != i)
				{
					Worker* temp = this->m_EmpArray[minorMax];
					this->m_EmpArray[minorMax] = this->m_EmpArray[i];
					this->m_EmpArray[i] = temp;					
				}
			}
			cout << "����ɹ���" << endl;
			this->Save();
			this->Show_Emp();
			break;
		}
	}
}

int WorkerManager::IsExist(int id)
{
	int index = -1;
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (this->m_EmpArray[i]->m_Id == id)
		{
			index = i;
			break;
		}
	}
	return index;
}

void WorkerManager::Find_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ�û�����ݣ�" << endl;
	}
	else
	{
		cout << "��ѡ����Ĳ��ҷ�ʽ��" << endl;
		cout << "1.��ְ����Ų���" << endl;
		cout << "2.��ְ����������" << endl;
		int select1 = 0;
		while (true)
		{
			while (!(cin >> select1))
			{
				cin.clear();
				while (cin.get() == '\n')
				{
					continue;
				}
				cout << "����ʧ�ܣ����������֣�" << endl;
			}
			if (select1 == 1)
			{
				cout << "��������Ҫ���ҵ�ְ����ţ�" << endl;
				int id = 0;
				while (!(cin >> id))
				{
					cin.clear();
					while (cin.get() == '\n')
					{
						continue;
					}
					cout << "����ʧ�ܣ����������֣�" << endl;
				}				
				int index = this->IsExist(id);
				if (index == -1)
				{
					cout << "����ʧ�ܣ����޴��ˣ�" << endl;
				}
				else
				{
					cout << "���ҵ�ְ�����Ϊ " << id << "��ְ��������Ϣ���£�" << endl;
					this->m_EmpArray[index]->ShowInfo();
					break;
				}				
			}
			else if (select1 == 2)
			{
				cout << "��������Ҫ���ҵ�ְ��������" << endl;
				string name;
				cin >> name;
				bool falg = false;
				for (int i = 0; i < this->m_EmpNum; i++)
				{
					if (name == this->m_EmpArray[i]->m_Name)
					{
						falg = true;
						cout << "���ҵ�ְ�����Ϊ " << this->m_EmpArray[i]->m_Id << " ��ְ��������Ϣ���£�" << endl;
						this->m_EmpArray[i]->ShowInfo();
					}
				}
				if (falg == false)
				{
					cout << "����ʧ�ܣ����޴��ˣ�" << endl;
				}
				break;
			}
			else
			{
				cout << "�����������������룡" << endl;
				continue;
			}
		}	
	}
	system("pause");
	system("cls");
}

void WorkerManager::Add_Emp()
{
	cout << "��������Ҫ��ӵ���ְ��������" << endl;
	int addNum = 0;
	while (!(cin >> addNum))//�������벻Ϊ�������͵������ַ�������������
	{
		cin.clear();
		while (cin.get() != '\n')
			continue;
		cout << "����������������֣�" << endl;
	}
	if (addNum > 0)
	{
		int newSize = this->m_EmpNum + addNum;
		Worker** newSpace = new Worker * [newSize];

		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}

		for (int i = 0; i < addNum; i++)
		{
			int id;
			string name;
			int dSelect;

			cout << "������� " << i + 1 << " ����ְ���ı�ţ�" << endl;

			while (true)//����ְ������Ƿ�ʹ��
			{
				while (!(cin >> id))//�������벻Ϊ�������͵������ַ�������������
				{
					cin.clear();
					while (cin.get() != '\n')
						continue;
					cout << "����������������֣�" << endl;
				}

				int temp = 0;
				for (int i = 0; i < this->m_EmpNum; i++)
				{
					
					if (id == this->m_EmpArray[i]->m_Id)
					{
						temp++;												
					}					
				}

				if (temp > 0)
				{
					cout << "ְ������ѱ�ʹ�ã�����������ְ����ţ�" << endl;
					continue;
				}
				else
				{
					cout << "ְ�������Ч��" << endl;
					break;
				}
			}
			

			cout << "������� " << i + 1 << " ����ְ����������" << endl;
			cin >> name;

			cout << "��ѡ���ְ����λ��" << endl;
			cout << "1.��ͨԱ��" << endl;
			cout << "2.����" << endl;
			cout << "3.�ܲ�" << endl;
			Worker* worker = NULL;

			while (true)
			{
				while (!(cin >> dSelect))//�������벻Ϊ�������͵������ַ�������������
				{
					cin.clear();
					while (cin.get() != '\n')
						continue;
					cout << "����������������֣�" << endl;
				}
				if (dSelect == 1)
				{
					worker = new Employee(id, name, dSelect);
					break;
				}
				else if (dSelect == 2)
				{
					worker = new Manager(id, name, dSelect);
					break;
				}
				else if (dSelect == 3)
				{
					worker = new Boss(id, name, dSelect);
					break;
				}
				else
				{
					cout << "����������������룡" << endl;
					continue;
				}
			}
			//����ע�ʹ���Ϊ��Ƶ��ʦԴ�룬û�м����û���������ݣ����������Ż�
			//while (!(cin >> dSelect))//�������벻Ϊ�������͵������ַ�������������
			//{
			//	cin.clear();
			//	while (cin.get() != '\n')
			//		continue;
			//	cout << "����������������֣�" << endl;
			//}
			//switch (dSelect)
			//{
			//case 1:
			//	worker = new Employee(id, name, dSelect);
			//	break;
			//case 2:
			//	worker = new Manager(id, name, dSelect);
			//	break;
			//case3:
			//	worker = new Boss(id, name, dSelect);
			//	break;
			//default:
			//{
			//	cout << "����������������룡" << endl;	
			//	system("pause");
			//	system("cls");
			//	return;
			//}			
			//	break;
			//}
			
			
			newSpace[this->m_EmpNum + i] = worker;
			

		}
		delete[] this->m_EmpArray;
		this->m_EmpArray = newSpace;
		this->m_EmpNum = newSize;
		this->m_FileIsEmpty = false;
		cout << "�ɹ������ " << addNum << " ����ְ����" << endl;
		this->Save();
	}
	else
	{
		cout << "�����������������룡" << endl;
	}
	system("pause");
	system("cls");
}
