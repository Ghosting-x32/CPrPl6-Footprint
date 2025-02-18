#include<iostream>
int Fill_array(double ar[], int n);
void Show_array(double ar[], int n);
void Reverse_array(double ar[], int n);
const int Acs = 5;

int main()
{
	using namespace std;
	double cs[Acs];
	int size = Fill_array(cs, Acs);
	Show_array(cs, size);
	Reverse_array(cs, size);
	Show_array(cs, size);
	Reverse_array((cs + 1), (size - 2));
	Show_array(cs, size);


	system("pause");
	return 0;
}

int Fill_array(double ar[], int n)
{
	using namespace std;
	cout << "请输入数组内容：" << endl;
	int i;
	for (i = 0; i < n; i++)
	{
		double temp;
		cout << "第" << i + 1 << "个：";
		cin >> temp;
		if (!cin)
		{
			cin.clear();
			while (cin.get() != '\n')
				continue;
			cout << "你的输入不正确！" << endl;
			break;
		}
		ar[i] = temp;
	}
	return i;
}

void Show_array(double ar[], int n)
{
	using namespace std;
	cout << "\n你输入的数组内容是：" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "第" << i + 1 << "个：";
		cout << ar[i] << endl;
	}
}

void Reverse_array(double ar[], int n)
{
	int i, j;
	for (i = 0, j = (n - 1); i < j; ++i, --j)
	{
		double x;
		x = ar[j];
		ar[j] = ar[i];
		ar[i] = x;
	}
}