#include<istream>
#include<string>
#include<fstream>

#include"WorkerManager.h"
#include"Worker.h"
#include"Employee.h"
#include"Manager.h"
#include"Boss.h"

using namespace std;


int main()
{
	//Worker* abc = NULL;
	//abc = new Employee(1, "����", 1);
	//abc->ShowInfo();
	//delete abc;

	//abc = new Manager(2, "����", 2);
	//abc->ShowInfo();
	//delete abc;

	//abc = new Boss(3, "����", 3);
	//abc->ShowInfo();
	//delete abc;
	//����Ϊ����4����Ĵ���

	WorkerManager wm;
	int choice = 0;
	while (true)
	{
		wm.ShowMenu();
		cout << "���������ѡ��" << endl;
		while (!(cin >> choice))//�������벻Ϊ�������͵������ַ�������������
		{
			cin.clear();
			while (cin.get() != '\n')
				continue;
			cout << "����������������֣�" << endl;
		}
		switch (choice)
		{
		case 0://�˳�ϵͳ
			wm.ExitSystem();
			//return 0;//Ч������ExitSystem()�����������exit��0��һ��
			break;
		case 1://����ְ��
			wm.Add_Emp();
			break;
		case 2://��ʾְ��
			wm.Show_Emp();
			break;
		case 3://ɾ��ְ��
			wm.Del_Emp();
			//������δ���Ϊ����IsExist()����
		//{
		//	int ret = wm.IsExist(9);
		//	if (ret == -1)
		//	{
		//		cout << "Ա�������ڣ�" << endl;
		//	}
		//	else
		//	{
		//		cout << "Ա�����ڣ�" << endl;
		//	}
		//}
			break;
		case 4://�޸�ְ��
			wm.Mod_Emp();
			break;
		case 5://����ְ��
			wm.Find_Emp();
			break;
		case 6://����ְ��
			wm.Sort_Emp();
			break;
		case 7://����ĵ�
			wm.Clean_File();
			break;
		default:
		{
			system("cls");
			cout << "����������������룡" << endl;
		}
			break;
		}
	}
	

	system("pause");
	return 0;
}

