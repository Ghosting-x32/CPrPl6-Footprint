#include<iostream>
#include<string>
#include<cfloat>
//#include<cstdlib>
//#include <stdexcept>// ����ͷ�ļ�
//#include <exception> // ����ͷ�ļ�

using namespace std;

bool hmean(double a, double b, double* ans);
// ȫ����ֹ������
//void customTerminate() {
//	cerr << "abnormal program termination\n";
//	exit(EXIT_FAILURE);
//}

int main()
{
	//set_terminate(customTerminate); // �����Զ�����ֹ����

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

		

		if (hmean(x, y, &z))
		{
			cout << "Harmonic mean of " << x << " and " << y << " is " << z << endl;

		}
		else
		{
			cout << "One value should not be the negative of the other - try again.\n";
			cout << "������뵼�·�ĸΪ0�ˣ����������룡" << endl;
		}

		
		cout << "Enter next set of numbers <q to quit>: ";


	}
	


	system("pause");
	return 0;
}


bool hmean(double a, double b, double * ans)
{

	if (a == -b)
	{
		*ans = DBL_MAX;
		return false;
		//cout << "untenable arguments to hmean()\n";
		//terminate(); // �����Զ�����ֹ����
		//abort();//���׼��������cerr��������Ϣabnormal program termination�������쳣��ֹ����Ȼ����ֹ����
	}
	else
	{
		*ans = 2.0 * a * b / (a + b);
		return true;
	}
	



}