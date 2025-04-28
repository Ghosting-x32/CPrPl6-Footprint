#include<iostream>
#include<string>
#include<cmath>

#include"bad_gmean.h"
#include"bad_hmean.h"

using namespace std;

double hmean(double a, double b);
double gmean(double a, double b);



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
			cout << "Harmonic mean of " << x << " and " << y << " is " << z << endl;

			cout << "Geometric mean of " << x << " and " << y << " is " << gmean(x, y) << endl;

			cout << "�����������ַ���ʼ���ԣ� q�����˳�: " << endl;
		}

		//catch (bad_gmean& hg)//catch��2���쳣�������2
		//{
		//	hg.mesg();
		//	cout << hg.what();//��3����Դ���			
		//	cout << "Sorry, you don't get to play any more.\n";
		//	break;
		//}

		catch (bad_hmean& bg)//catch��1���쳣�������1
		{//��3����Դ���---�����쳣���Ϳ��Բ��������쳣
			bg.mesg();
			cout << bg.what();
			cout << "Sorry, you don't get to play any more.\n";
			//cout << "�����������ַ���ʼ���ԣ� q�����˳�\nTry again.\n";
			break;
		}

		
		


	}



	system("pause");
	return 0;
}


double hmean(double a, double b)
{
	if (a == -b)
	{
		throw bad_hmean(a, b);//�׳��쳣,�쳣������Ϊbad_hmean---�׳�һ��bad_hmean�����������
	}
	return 2.0 * a * b / (a + b);//�������ĵ���ƽ����


}

double gmean(double a, double b)
{
	if (a < 0 || b < 0)
	{
		throw bad_gmean(a, b);//�׳��쳣,�쳣������Ϊbad_gmean---�׳�һ��bad_gmean�����������

	}

	return sqrt(a * b);//�������ļ���ƽ��ֵ
}