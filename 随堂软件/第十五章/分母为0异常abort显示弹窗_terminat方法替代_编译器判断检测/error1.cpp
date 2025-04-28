#include<iostream>
#include<string>
#include<cstdlib>
#include <stdexcept>// ����ͷ�ļ�
#include <exception> // ����ͷ�ļ�

using namespace std;

double hmean(double a, double b);
// ȫ����ֹ������
void customTerminate() {
	cerr << "abnormal program termination\n";
	exit(EXIT_FAILURE);
}

int main()
{
	set_terminate(customTerminate); // �����Զ�����ֹ����

	double x, y, z;	
	char ch;
	cout << "�����������ַ���ʼ���ԣ� q�����˳�" << endl;
	while (cin >> ch && ch != 'q')
	{
		while (cin.get() != '\n')
		{
			continue;
		}
		cout << "Enter two numbers: ";
		while (!(cin >> x >> y))
		{
			cin.clear();
			while (cin.get() != '\n')
			{
				continue;
			}
			cout << "Incorrect input, please enter a number!" << endl;
		}

		while (cin.get() != '\n')
		{
			continue;
		}

		z = hmean(x, y);
		cout << "Harmonic mean of " << x << " and " << y << " is " << z << endl;
		cout << "Enter next set of numbers <q to quit>: ";


	}
	


	system("pause");
	return 0;
}


double hmean(double a, double b)
{

	if (a == -b)
	{
		cout << "untenable arguments to hmean()\n";
		terminate(); // �����Զ�����ֹ����
		//abort();//���׼��������cerr��������Ϣabnormal program termination�������쳣��ֹ����Ȼ����ֹ����
	}
	return 2.0 * a * b / (a + b);



}