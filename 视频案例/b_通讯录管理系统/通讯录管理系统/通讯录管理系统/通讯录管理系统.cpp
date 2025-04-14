#include<iostream>
#include<string>
#define MAX 1000
using namespace std;

//设计联系人结构体
struct Person
{
	string m_Name;//姓名
	int m_Sex;//性别
	int m_Age;//年龄
	string m_Phone;//电话
	string m_Addr;//地址
};

//设计通讯录结构体
struct Addressbooks
{
	Person personArray[MAX];
	int m_Size;
};

void showMenu();//菜单界面函数
void addPerson(Addressbooks* abs);//添加联系人函数
void showPerson(Addressbooks* abs);//显示联系人函数
int isExist(Addressbooks* abs, string name);//检查联系人是否存在函数
void deletePerson(Addressbooks* abs);//删除联系人函数
void findPerson(Addressbooks* abs);//查找联系人函数
void modifyPerson(Addressbooks* abs);//修改联系人函数
void cleanPerson(Addressbooks* abs);//清空通讯录函数


int main()
{
	Addressbooks abs;//创建一个通讯录
	abs.m_Size = 0 ;//初始化通讯录联系人个数为0

	int select = 0;
	while (true)
	{
		showMenu();
		cin >> select;
		switch (select)
		{
		case 1://1.添加联系人
			addPerson(&abs);
			break;
		case 2://2.显示联系人
			showPerson(&abs);
			break;
		case 3://3.删除联系人
			deletePerson(&abs);
			//下面这段注释掉的代码是测试isExist函数，
		/*{
			cout << "请输入需要删除的联系人姓名：" << endl;
			string name;
			cin >> name;
			if (isExist(&abs, name) == -1)
			{
				cout << "没有找到此联系人！" << endl;
			}
			else
			{
				cout << "找到了此联系人！" << endl;
			}
		}*/
			break;
		case 4://4.查找联系人
			findPerson(&abs);
			break;
		case 5://5.修改联系人
			modifyPerson(&abs);
			break;
		case 6://6.清空联系人
			cleanPerson(&abs);
			break;
		case 0://0.退出通讯录
			cout << "欢迎下次使用！" << endl;
			system("pause");
			system("cls");
			return 0;
			break;
		default:
			cout << "输入错误，请重新输入！" << endl;
			system("pause");
			system("cls");
			break;
		}
	}

	system("pause");
	return 0;
}

//菜单界面函数
void showMenu()
{
	cout << "************************" << endl;
	cout << "***** 1.添加联系人 *****" << endl;
	cout << "***** 2.显示联系人 *****" << endl;
	cout << "***** 3.删除联系人 *****" << endl;
	cout << "***** 4.查找联系人 *****" << endl;
	cout << "***** 5.修改联系人 *****" << endl;
	cout << "***** 6.清空联系人 *****" << endl;
	cout << "***** 0.退出通讯录 *****" << endl;
	cout << "************************" << endl;
}

void addPerson(Addressbooks* abs)//添加联系人函数
{
	if (abs->m_Size >= MAX)
	{
		cout << "通讯录已满，无法添加！" << endl;
		return;
	}
	else
	{
		cout << "请输入联系人姓名：" << endl;//添加联系人姓名
		string name;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;

		cout << "请输入联系人性别： " << endl;//添加联系人性别
		cout << "1---男" << endl;
		cout << "2---女" << endl;
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
				cout << "输入有误，请重新输入！" << endl;
			}
		}
		
		cout << "请输入联系人年龄： " << endl;//添加联系人年龄
		int age;
		cin >> age;
		abs->personArray[abs->m_Size].m_Age = age;

		cout << "请输入联系人电话： " << endl;//添加联系人电话
		string phone;
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;

		cout << "请输入联系人地址： " << endl;//添加联系人地址
		string address;
		cin >> address;
		abs->personArray[abs->m_Size].m_Addr = address;

		abs->m_Size++;//更新通讯录人数
		cout << "恭喜你添加成功！！" << endl;
		system("pause");//按任意键继续
		system("cls");//清屏
	}
}

void showPerson(Addressbooks* abs)//显示联系人函数
{
	if (abs->m_Size == 0)//判断通讯录是否已满
	{
		cout << "当前通讯录为空！" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "姓名： " << abs->personArray[i].m_Name << "\t";//插入水平制表符使输出清晰显示
			cout << "性别： " << (abs->personArray[i].m_Sex == 1 ? "男" : "女") << "\t";//将1，2对应转换为“男”，“女”
			cout << "年龄： " << abs->personArray[i].m_Age << "\t";
			cout << "电话： " << abs->personArray[i].m_Phone << "\t";
			cout << "地址： " << abs->personArray[i].m_Addr << endl;
		}
	}
	system("pause");
	system("cls");
}

int isExist(Addressbooks* abs, string name)//检查联系人是否存在函数,如果存在，显示存在的地址，如果不存在，显示-1
{
	for (int i = 0; i < abs->m_Size; i++)
	{
		if (abs->personArray[i].m_Name == name)//按联系人姓名进行检测
		{
			return i;//检测到联系人，返回其在通讯录结构中联系人结构数组的下标
		}
	}
	return -1;
}

void deletePerson(Addressbooks* abs)//删除联系人函数
{
	cout << "请输入需要删除的联系人名字： " << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);//检查联系人是否存在
	if (ret != -1)
	{//联系人存在，执行删除操作
		for (int i = ret; i < abs->m_Size; i++)
		{
			abs->personArray[i] = abs->personArray[i + 1];//将存在的联系人的下标以后的联系人数据全部向前移动
		}
		cout << "删除成功！" << endl;
		abs->m_Size--;//更新联系人个数
	}
	else
	{
		cout << "查无此人！" << endl;
	}
	system("pause");
	system("cls");
}

void findPerson(Addressbooks* abs)//查找联系人函数
{
	cout << "请输入需要查找的联系人姓名： " << endl;
	string name;
	cin >> name;

	int ret = isExist(abs, name);;//检查联系人是否存在
	if (ret == -1)
	{
		cout << "查无此人！" << endl;
	}
	else
	{
		cout << "姓名： " << abs->personArray[ret].m_Name << "\t";//插入水平制表符使输出清晰显示
		cout << "性别： " << (abs->personArray[ret].m_Sex == 1 ? "男" : "女") << "\t";//将1，2对应转换为“男”，“女”
		cout << "年龄： " << abs->personArray[ret].m_Age << "\t";
		cout << "电话： " << abs->personArray[ret].m_Phone << "\t";
		cout << "地址： " << abs->personArray[ret].m_Addr << endl;
	}
	system("pause");
	system("cls");
}

void modifyPerson(Addressbooks* abs)//修改联系人函数
{
	cout << "请输入需要修改的联系人姓名： " << endl;
	string name;
	cin >> name;

	int ret = isExist(abs, name);
	if (ret == -1)
	{
		cout << "查无此人！" << endl;
	}
	else//选择需要修改的信息
	{
		int select1 = 0;
		
		while (true)
		{
			cout << "******************" << endl;
			cout << "*** 1.修改姓名 ***" << endl;
			cout << "*** 2.修改性别 ***" << endl;
			cout << "*** 3.修改年龄 ***" << endl;
			cout << "*** 4.修改电话 ***" << endl;
			cout << "*** 5.修改地址 ***" << endl;
			cout << "*** 6.退出修改 ***" << endl;
			cout << "******************" << endl;
			cout << "请输入需要修改的信息： " << endl;
			cin >> select1;
			switch (select1)
			{
			case 1://修改姓名
			{
				cout << "请输入联系人姓名：" << endl;
				string name1;
				cin >> name1;
				abs->personArray[ret].m_Name = name1;
				cout << "修改成功！" << endl;
			}
				break;
			case 2://修改性别
			{
				cout << "请输入联系人性别： " << endl;
				cout << "1---男" << endl;
				cout << "2---女" << endl;
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
						cout << "输入有误，请重新输入！" << endl;
					}
				}
				cout << "修改成功！" << endl;
			}
				break;
			case 3://修改年龄
			{
				cout << "请输入联系人年龄： " << endl;
				int age;
				cin >> age;
				abs->personArray[ret].m_Age = age;
				cout << "修改成功！" << endl;
			}
				break;
			case 4://修改电话
			{
				cout << "请输入联系人电话： " << endl;//添加联系人电话
				string phone;
				cin >> phone;
				abs->personArray[ret].m_Phone = phone;
				cout << "修改成功！" << endl;
			}
				break;
			case 5://修改地址
			{
				cout << "请输入联系人地址： " << endl;//添加联系人地址
				string address;
				cin >> address;
				abs->personArray[ret].m_Addr = address;
				cout << "修改成功！" << endl;
			}
				break;
			case 6:
				system("pause");
				system("cls");
				return;
				break;
			default:
				cout << "输入错误,请重新输入！" << endl;
				break;
			}
		}
	}
}

void cleanPerson(Addressbooks* abs)//清空通讯录函数
{
	abs->m_Size = 0;//将联系人记录人数设置为0，实现逻辑上的清空
	cout << "通讯录已清空！" << endl;
	system("pause");
	system("cls");
}