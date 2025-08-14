#include<iostream>

using namespace std;

struct things1
{
	char ch;
	int a;
	double x;

};

struct things2
{
	int a;
	double x;
	char ch;

};


int main()
{
	things1 th1;
	things2 th2;


	cout << "char alignment: " << alignof(char) << endl;
	cout << "int alignment: " << alignof(int) << endl;
	cout << "double alignment: " << alignof(double) << endl;
	cout << "things1 alignment: " << alignof(things1) << endl;
	cout << "things2 alignment: " << alignof(things2) << endl;
	cout << "things1 size: " << sizeof(things1) << endl;
	cout << "things2 size: " << sizeof(things2) << endl;
	



	system("pause");
	return 0;
}

/*���������
char alignment: 1
int alignment: 4
double alignment: 8
things1 alignment: 8
things2 alignment: 8//�����ṹ�Ķ��䷽ʽ����8��������
things1 size: 16
things2 size: 24//�ṹ�ĳ�Ա˳��ͬ���½ṹ�Ĵ�С��ͬ
*/
