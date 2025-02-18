#include<iostream>
const int cjgs = 10;
int f1(double ar[], int n);
void f2(const double ar[], int n);
double f3(const double ar[], int n);

int main()
{
	using namespace std;
	double fcj[cjgs];
	int size = f1(fcj, cjgs);
	f2(fcj, size);
	double pj = f3(fcj, size);
	cout << "\n你的平均成绩是：" << pj << endl;


	cout << endl;
	system("pause");
	return 0;
}

int f1(double ar[], int n)
{
	using namespace std;
	double temp;
	int i;
	for (i = 0; i < n; i++)
	{
		cout << "请输入你的高尔夫成绩" << i + 1 << ": ";
		cin >> temp;
		if (!cin)
		{
			cin.clear();
			while (cin.get() != '\n')
				continue;
			cout << "输入的不是正确的成绩!\n";
			break;
		}
		else if (temp < 0)
			break;
		ar[i] = temp;
	}
	return i;
}

void f2(const double ar[], int n)
{
	using namespace std;
	cout << "\n你的高尔夫成绩分别是：\n";
	for (int i = 0; i < n; i++)
		cout << "成绩" << i + 1 << ": " << ar[i] << endl;
}

double f3(const double ar[], int n)
{
	double pjcj;
	double total = 0;
	for (int i = 0; i < n; i++)
		total += ar[i];
	pjcj = total / n;
	return pjcj;
}