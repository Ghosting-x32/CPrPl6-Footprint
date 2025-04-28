#include<iostream>
#include<string>

using namespace std;

double hmean(double a, double b);


int main()
{


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


		try//try��
		{
			z = hmean(x, y);
		}

		catch (const char* s)//catch�飬�쳣�������
		{
			cout << s << endl;
			cout << "�����������ַ���ʼ���ԣ� q�����˳�\nEnter a new pair of numbers: ";
			continue;
		}

		cout << "Harmonic mean of " << x << " and " << y << " is " << z << endl;
		cout << "�����������ַ���ʼ���ԣ� q�����˳�: ";


	}



	system("pause");
	return 0;
}


double hmean(double a, double b)
{
	if (a == -b)
	{
		throw "bad hmean() arguments: a = -b not allowed\n������뵼�·�ĸΪ0�����������룡";//�׳��쳣
	}
	return 2.0 * a * b / (a + b);


}