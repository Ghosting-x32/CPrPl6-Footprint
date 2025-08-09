#include<iostream>
#include<string>
#include<cmath>


using namespace std;

int main()
{
	cout.setf(ios_base::left, ios_base::adjustfield);//�����
	cout.setf(ios_base::showpos);//��ʾ+
	cout.setf(ios_base::showpoint);//��ʾС����
	cout.precision(3);//Ĭ��״̬����---��λ��
	//��ѧ�������Ͷ����ʾ��״̬�µľ�����С������λ��

	ios_base::fmtflags old = cout.setf(ios_base::scientific, ios_base::floatfield);//��ѧ������
	//������ǰ�ĸ�ʽ��ǩ

	cout << "Left Justification:\n";
	long n;
	for (n = 1; n <= 41; n += 10)
	{
		cout.width(4);
		cout << n << "|";
		cout.width(12);
		cout << sqrt(double(n)) << "|\n";

	}


	cout.setf(ios_base::internal, ios_base::adjustfield);//���Ż����ǰ׺����룬ֵ�Ҷ���
	cout.setf(old, ios_base::floatfield);//����floatfield��ǩΪ��ǰ�ĸ�ʽ��ǩ
	//��ǰ����һ���ֵ��Ĭ��״̬---�Ȳ��ǿ�ѧ������Ҳ���Ƕ����ʾ��

	//��ʱ��Ĭ��״̬����---��λ��3
	cout << "Internal Justification:\n";
	for (n = 1; n <= 41; n += 10)
	{
		cout.width(4);
		cout << n << "|";
		cout.width(12);
		cout << sqrt(double(n)) << "|\n";

	}

	cout.setf(ios_base::right, ios_base::adjustfield);//�Ҷ���
	cout.setf(ios_base::fixed, ios_base::floatfield);//�����ʾ��
	cout << "Right Justification:\n";
	for (n = 1; n <= 41; n += 10)
	{
		cout.width(4);
		cout << n << "|";
		cout.width(12);
		cout << sqrt(double(n)) << "|\n";

	}











	system("pause");
	return 0;
}