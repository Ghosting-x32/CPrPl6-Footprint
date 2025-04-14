#include"WorkerManager.h"

WorkerManager::WorkerManager()
{
	//1.文件不存在的情况初始化
	ifstream ifs1;
	ifs1.open(FILENAME, ios::in);

	if (!ifs1.is_open())
	{
		cout << "文件不存在！" << endl;
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs1.close();
		return;
	}
	//2.文件存在，但数据为空
	char ch;
	ifs1 >> ch;
	if (ifs1.eof())
	{
		cout << "文件数据为空！" << endl;
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs1.close();
		return;
	}
	//3.文件存在，且有数据
	int num = this->get_EmpNum();
	cout << "职工人数为：" << num << endl;
	this->m_EmpNum = num;

	this->m_FileIsEmpty = false;

	this->m_EmpArray = new Worker * [this->m_EmpNum];
	this->init_Emp();	
	//以下为测试初始化m_EmpArray的代码
	//for (int i = 0; i < this->m_EmpNum; i++)
	//{
	//	cout << "职工编号: " << this->m_EmpArray[i]->m_Id
	//		<< "\t职工姓名: " << this->m_EmpArray[i]->m_Name
	//		<< "\t岗位: " << this->m_EmpArray[i]->m_DeptId << endl;
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
	cout << "********* 欢迎使用职工管理系统！ *********" << endl;
	cout << "************ 0.退出管理程序 **************" << endl;
	cout << "************ 1.增加职工信息 **************" << endl;
	cout << "************ 2.显示职工信息 **************" << endl;
	cout << "************ 3.删除离职职工 **************" << endl;
	cout << "************ 4.修改职工信息 **************" << endl;
	cout << "************ 5.查找职工信息 **************" << endl;
	cout << "************ 6.按照编号排序 **************" << endl;
	cout << "************ 7.清空所有文档 **************" << endl;
	cout << "******************************************" << endl;
}

void WorkerManager::ExitSystem()
{
	system("cls");
	cout << "欢迎下次使用！" << endl;
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
		cout << "文件不存在或没有数据！" << endl;
	}
	else
	{
		cout << "请输入你要删除的职工编号：" << endl;
		int id;
		while (!(cin >> id))
		{
			cin.clear();
			while (cin.get() == '\n')
			{
				continue;
			}
			cout << "输入失败，请输入数字！" << endl;
		}

		int index = this->IsExist(id);
		if (index == -1)
		{
			cout << "删除失败，没有找到该职工！" << endl;
		}
		else
		{
			for (int i = index; i < this->m_EmpNum - 1; i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_EmpNum--;
			cout << "删除成功！" << endl;
			this->Save();
		}
	}
	system("pause");
	system("cls");
}

void WorkerManager::Clean_File()
{
	cout << "确认清空？" << endl;
	cout << "1.确认" << endl;
	cout << "2.返回" << endl;
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
			cout << "输入失败，请输入数字！" << endl;
		}
		if (select == 1)
		{
			ofstream ofs1;
			ofs1.open(FILENAME, ios::trunc);//如果文件已存在，删除文件所有内容

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
			cout << "数据清空完成！" << endl;
			break;
		}
		else if(select == 2)
		{
			cout << "数据保留成功，没有清空！" << endl;
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

void WorkerManager::Mod_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或没有数据！" << endl;
	}
	else
	{
		cout << "请输入需要修改的职工编号：" << endl;
		int id;
		while (!(cin >> id))
		{
			cin.clear();
			while (cin.get() == '\n')
			{
				continue;
			}
			cout << "输入失败，请输入数字！" << endl;
		}

		int index = this->IsExist(id);
		if (index == -1)
		{
			cout << "修改失败，查无此人！" << endl;		
		}
		else
		{
			cout << "查到编号为 " << id << " 的职工！" << endl;
			cout << "**********************" << endl;
			cout << "*** 1.修改职工编号 ***" << endl;
			cout << "*** 2.修改职工姓名 ***" << endl;
			cout << "*** 3.修改职工岗位 ***" << endl;
			cout << "**********************" << endl;
			cout << "请选择需要修改的项目：" << endl;
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
					cout << "输入失败，请输入数字！" << endl;
				}
				if (select1 == 1)
				{
					cout << "请输入新职工编号：" << endl;
					int id1 = 0;
					while (true)//检验职工编号是否被使用
					{
						while (!(cin >> id1))//检验输入不为数字类型的其他字符，并重置输入
						{
							cin.clear();
							while (cin.get() != '\n')
								continue;
							cout << "输入错误，请输入数字！" << endl;
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
							cout << "职工编号已被使用，请重新输入职工编号：" << endl;
							continue;
						}
						else
						{
							cout << "职工编号有效！" << endl;
							break;
						}
					}
					this->m_EmpArray[index]->m_Id = id1;
					this->Save();
					break;
				}
				else if (select1 == 2)
				{
					cout << "请输入新的职工姓名：" << endl;
					string name;
					cin >> name;
					this->m_EmpArray[index]->m_Name = name;
					this->Save();
					break;
				}
				else if (select1 == 3)
				{
					cout << "请选择新的职工岗位：" << endl;
					cout << "1.普通员工" << endl;
					cout << "2.经理" << endl;
					cout << "3.总裁" << endl;
					int select2 = 0;
					while (true)
					{
						while (!(cin >> select2))//检验输入不为数字类型的其他字符，并重置输入
						{
							cin.clear();
							while (cin.get() != '\n')
								continue;
							cout << "输入错误，请输入数字！" << endl;
						}
						if (select2 == 1 || select2 == 2 || select2 == 3)
						{
							this->m_EmpArray[index]->m_DeptId = select2;
							this->Save();
							break;
						}					
						else
						{
							cout << "输入错误，请重新输入！" << endl;
							continue;
						}
					}
					break;
				}
				else
				{
					cout << "输入有误，请重新输入！" << endl;
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
		cout << "文件不存在或没有数据！" << endl;
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
		cout << "文件不存在或没有数据！" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "请选择你的排序方式：" << endl;
		cout << "1.按照职工编号进行升序排列" << endl;
		cout << "2.按照职工编号进行降序排列" << endl;
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
				cout << "输入有误，请输入数字！" << endl;
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
						cout << "输入有误，请重新输入！" << endl;
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
			cout << "排序成功！" << endl;
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
		cout << "文件不存在或没有数据！" << endl;
	}
	else
	{
		cout << "请选择你的查找方式：" << endl;
		cout << "1.按职工编号查找" << endl;
		cout << "2.按职工姓名查找" << endl;
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
				cout << "输入失败，请输入数字！" << endl;
			}
			if (select1 == 1)
			{
				cout << "请输入你要查找的职工编号：" << endl;
				int id = 0;
				while (!(cin >> id))
				{
					cin.clear();
					while (cin.get() == '\n')
					{
						continue;
					}
					cout << "输入失败，请输入数字！" << endl;
				}				
				int index = this->IsExist(id);
				if (index == -1)
				{
					cout << "查找失败，查无此人！" << endl;
				}
				else
				{
					cout << "查找到职工编号为 " << id << "的职工，其信息如下：" << endl;
					this->m_EmpArray[index]->ShowInfo();
					break;
				}				
			}
			else if (select1 == 2)
			{
				cout << "请输入你要查找的职工姓名：" << endl;
				string name;
				cin >> name;
				bool falg = false;
				for (int i = 0; i < this->m_EmpNum; i++)
				{
					if (name == this->m_EmpArray[i]->m_Name)
					{
						falg = true;
						cout << "查找到职工编号为 " << this->m_EmpArray[i]->m_Id << " 的职工，其信息如下：" << endl;
						this->m_EmpArray[i]->ShowInfo();
					}
				}
				if (falg == false)
				{
					cout << "查找失败，查无此人！" << endl;
				}
				break;
			}
			else
			{
				cout << "输入有误，请重新输入！" << endl;
				continue;
			}
		}	
	}
	system("pause");
	system("cls");
}

void WorkerManager::Add_Emp()
{
	cout << "请输入需要添加的新职工人数：" << endl;
	int addNum = 0;
	while (!(cin >> addNum))//检验输入不为数字类型的其他字符，并重置输入
	{
		cin.clear();
		while (cin.get() != '\n')
			continue;
		cout << "输入错误，请输入数字！" << endl;
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

			cout << "请输入第 " << i + 1 << " 个新职工的编号：" << endl;

			while (true)//检验职工编号是否被使用
			{
				while (!(cin >> id))//检验输入不为数字类型的其他字符，并重置输入
				{
					cin.clear();
					while (cin.get() != '\n')
						continue;
					cout << "输入错误，请输入数字！" << endl;
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
					cout << "职工编号已被使用，请重新输入职工编号：" << endl;
					continue;
				}
				else
				{
					cout << "职工编号有效！" << endl;
					break;
				}
			}
			

			cout << "请输入第 " << i + 1 << " 个新职工的姓名：" << endl;
			cin >> name;

			cout << "请选择该职工岗位！" << endl;
			cout << "1.普通员工" << endl;
			cout << "2.经理" << endl;
			cout << "3.总裁" << endl;
			Worker* worker = NULL;

			while (true)
			{
				while (!(cin >> dSelect))//检验输入不为数字类型的其他字符，并重置输入
				{
					cin.clear();
					while (cin.get() != '\n')
						continue;
					cout << "输入错误，请输入数字！" << endl;
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
					cout << "输入错误，请重新输入！" << endl;
					continue;
				}
			}
			//以下注释代码为视频老师源码，没有检验用户输入的内容，上面做了优化
			//while (!(cin >> dSelect))//检验输入不为数字类型的其他字符，并重置输入
			//{
			//	cin.clear();
			//	while (cin.get() != '\n')
			//		continue;
			//	cout << "输入错误，请输入数字！" << endl;
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
			//	cout << "输入错误，请重新输入！" << endl;	
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
		cout << "成功添加了 " << addNum << " 名新职工！" << endl;
		this->Save();
	}
	else
	{
		cout << "输入有误，请重新输入！" << endl;
	}
	system("pause");
	system("cls");
}
