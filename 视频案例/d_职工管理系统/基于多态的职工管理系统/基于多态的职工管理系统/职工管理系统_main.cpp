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
	//abc = new Employee(1, "张三", 1);
	//abc->ShowInfo();
	//delete abc;

	//abc = new Manager(2, "王五", 2);
	//abc->ShowInfo();
	//delete abc;

	//abc = new Boss(3, "马六", 3);
	//abc->ShowInfo();
	//delete abc;
	//以上为测试4个类的代码

	WorkerManager wm;
	int choice = 0;
	while (true)
	{
		wm.ShowMenu();
		cout << "请输入你的选择！" << endl;
		while (!(cin >> choice))//检验输入不为数字类型的其他字符，并重置输入
		{
			cin.clear();
			while (cin.get() != '\n')
				continue;
			cout << "输入错误，请输入数字！" << endl;
		}
		switch (choice)
		{
		case 0://退出系统
			wm.ExitSystem();
			//return 0;//效果和在ExitSystem()函数里面添加exit（0）一样
			break;
		case 1://增加职工
			wm.Add_Emp();
			break;
		case 2://显示职工
			wm.Show_Emp();
			break;
		case 3://删除职工
			wm.Del_Emp();
			//下面这段代码为测试IsExist()函数
		//{
		//	int ret = wm.IsExist(9);
		//	if (ret == -1)
		//	{
		//		cout << "员工不存在！" << endl;
		//	}
		//	else
		//	{
		//		cout << "员工存在！" << endl;
		//	}
		//}
			break;
		case 4://修改职工
			wm.Mod_Emp();
			break;
		case 5://查找职工
			wm.Find_Emp();
			break;
		case 6://排序职工
			wm.Sort_Emp();
			break;
		case 7://清空文档
			wm.Clean_File();
			break;
		default:
		{
			system("cls");
			cout << "输入错误，请重新输入！" << endl;
		}
			break;
		}
	}
	

	system("pause");
	return 0;
}

