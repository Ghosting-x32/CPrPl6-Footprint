#include<iostream>
#include"Useless.h"

using namespace std;



int main()
{
	{
		Useless one(10, 'x');
		Useless two = one;
		Useless three(20, 'o');
		Useless four(one + three);
		//���������û�����ƶ����캯���͸��ƹ��캯������Ϊ������ֵ�Ż���RVO��
		//temp ֱ���� four ���ڴ�λ�ù��죨RVO��
		//1.RVO ��Ĭ�������Ҳ��ɽ��õĺ����Ż�
		//2.�� C++17 ģʽ�£�RVO �����Ա�׼ǿ��Ҫ�����Ϊ
		//3.���Ƿ��ϱ�׼�Ļ����Ż�����Ӧǿ�Ʊ���

		//����g++���б����Ч��һ��



		//���������
	    /*int, char constructor called : number of objects : 1
		number of elements : 10 Data address : 0000028E42B358E0
		copy const called; number of objects : 2
		number of elements : 10 Data address : 0000028E42B35AC0
		int, char constructor called : number of objects : 3
		number of elements : 20 Data address : 0000028E42B35D40
		Entering operator+()
		int constructor called; number of objects : 4
		number of elements : 30 Data address : 0000028E42B30B40
		temp object :
	    Leaving operator+()----------------------------------------------����Useless operator+(const Useless& f)const;��������ֱ��������*1*�Ĵ��룬û�����ƶ����캯��
		object one : xxxxxxxxxx
		object two : xxxxxxxxxx
		object three : oooooooooooooooooooo
		object four : xxxxxxxxxxoooooooooooooooooooo
		destructor called : objects left : 3
		deleted object :
	    number of elements : 30 Data address : 0000028E42B30B40
		destructor called : objects left : 2
		deleted object :
	    number of elements : 20 Data address : 0000028E42B35D40
		destructor called : objects left : 1
		deleted object :
	    number of elements : 10 Data address : 0000028E42B35AC0
		destructor called : objects left : 0
		deleted object :
	    number of elements : 10 Data address : 0000028E42B358E0
		�밴���������. . .*/

		//*1*
		cout << "object one: ";
		one.ShowData();
		cout << "object two: ";
		two.ShowData();
		cout << "object three: ";
		three.ShowData();
		cout << "object four: ";
		four.ShowData();
	
	
	}//����������ʾ��������

	system("pause");
	return 0;
}