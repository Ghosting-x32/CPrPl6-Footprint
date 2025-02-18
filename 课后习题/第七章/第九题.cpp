#include<iostream>
using namespace std;
const int SLEN = 30;
struct student
{
	char fullname[SLEN];
	char hobby[SLEN];
	int ooplevel;
};
int getinfo(student pa[], int n);
void display1(student st);
void display2(const student* ps);
void display3(const student pa[], int n);


int main()
{
	cout << "Enter class size:(或者输入q结束）";
	int class_size;
	while (cin >> class_size)
	{
		if (class_size > 0)
		{
			student* ptr_stu = new student[class_size];
			int entered = getinfo(ptr_stu, class_size);
			cout << endl << endl;
			for (int i = 0; i < entered; i++)
			{
				cout << "你的第" << i + 1 << "个student内容是：" << endl;
				display1(ptr_stu[i]);
				cout << endl;
				cout << "你的第" << i + 1 << "个student内容是：" << endl;
				display2(&ptr_stu[i]);
				cout << endl << endl;
			}
			display3(ptr_stu, entered);
			delete[] ptr_stu;
			break;
		}
		else
		{
			cout << "请输入正确的class!!\a\n";
			cout << "Enter class size:(或者输入q结束）";
		}
	}
	cout << "Done!\a\a\n";




	system("pause");
	return 0;
}

int getinfo(student pa[], int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		cout << "\n请输入第" << i + 1 << "个ooplevel:";
		cin >> pa[i].ooplevel;
		cin.get();
		if (!cin)
		{
			cin.clear();
			while (cin.get() != '\n')
				continue;
			cout << "输入了不正确的ooplevel!!\a\n";
			break;
		}
		cout << "请输入第" << i + 1 << "个fullname:";
		cin.getline(pa[i].fullname, SLEN);
		cout << "请输入第" << i + 1 << "个hobby:";
		cin.getline(pa[i].hobby, SLEN);
	}
	return i;
}

void display1(student st)
{
	cout << "fullname: " << st.fullname << endl
		<< "hobby: " << st.hobby << endl
		<< "opplevel: " << st.ooplevel << endl;
}

void display2(const student* ps)
{
	cout << "fullname: " << ps -> fullname << endl
		<< "hobby: " << ps -> hobby << endl
		<< "opplevel: " << ps -> ooplevel << endl;
}

void display3(const student pa[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "第" << i + 1 << "个fullname:";
		cout << pa[i].fullname << endl;
		cout << "第" << i + 1 << "个hobby:";
		cout << pa[i].hobby << endl;
		cout << "第" << i + 1 << "个ooplevel:";
		cout << pa[i].ooplevel << endl << endl;
	}
}