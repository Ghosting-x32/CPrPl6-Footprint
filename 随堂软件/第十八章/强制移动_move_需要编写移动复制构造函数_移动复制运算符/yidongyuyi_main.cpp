#include<iostream>
#include"Useless.h"

using namespace std;



int main()
{
	{
		Useless one(10, 'x');
		Useless two = one + one;//ԭ������ʹ���ƶ����ƹ��캯��������RVO��
		cout << "object one: ";
		one.ShowData();
		cout << "object two: ";
		two.ShowData();

		Useless three, four;
		cout << "three = one\n";
		three = one;//ʹ�ó��渳ֵ�����
		cout << "now object three = ";
		three.ShowData();
		cout << "and object one = ";
		one.ShowData();

		cout << "four = one + two\n";
		four = one + two;//ʹ���ƶ���ֵ�����
		cout << "now object four = ";
		four.ShowData();

		cout << "four = move(one)\n";
		four = move(one);//ǿ��ʹ���ƶ���ֵ�����
		cout << "now object four = ";
		four.ShowData();
		cout << "and object one = ";
		one.ShowData();


	
	
	}//����������ʾ��������

	system("pause");
	return 0;
}