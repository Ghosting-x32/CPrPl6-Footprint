#include<iostream>
#include<string>
#include<cmath>
#include<iomanip>


using namespace std;

int main()
{
	cout << fixed << right;//���Ʒ�ʹ�ö����ʾ�����Ҷ���
	cout << setw(6) << "N" << setw(14) << "square root" << setw(15) << "fourth root\n";
	//ͷ�ļ�<iomanip>�ṩ�Ŀ��Ʒ��������ֶο��

	double root;
	for (int n = 10; n <= 100; n += 10)
	{
		root = sqrt(double(n));
		cout << setw(6) << setfill('.') << n
			<< setfill(' ') << setw(12) << setprecision(3) << root
			//ͷ�ļ�<iomanip>�ṩ�Ŀ��Ʒ�����������ַ��������ֶο�ȣ����þ���
			<< setw(14) << setprecision(4) << sqrt(root) << endl;

	}





	system("pause");
	return 0;
}