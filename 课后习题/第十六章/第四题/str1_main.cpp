#include<iostream>
#include<string>
#include<algorithm>
#include<iterator>

using namespace std;

int reduce(long ar[], int n);
void show(const long& lo);

int main()
{
	long arlo[8] = { 3, 6, 9, 2, 5, 6, 5, 1 };
	//��̬�����޷�ɾ��Ԫ�أ�ֻ�����߼��ϵ�ɾ��---�����ʺ�����Ҫɾ����Ԫ��
	int a = reduce(arlo, 8);
	cout << "����ȥ�غ��arloԪ����ĿΪ��" << a << endl;
	cout << "����ȥ�غ��arlo��������Ϊ��" << endl;
	for_each(arlo, arlo + a, show);//�߼��ϵ�ɾ��
	cout << endl;
	


	system("pause");
	return 0;
}


int reduce(long ar[], int n)
{
	int temp = 0;
	sort(ar, ar + n);
	cout << "��������" << endl;
	for_each(ar, ar + n, show);
	cout << endl;

	auto it1 = unique(ar, ar + n);//�㷨uniqueɾ���������������ظ���Ԫ�أ�����ȥ�غ���������λ��--����һ����β
	//ȥ�غ�uniqueֻ���㷨�������Զ��������鳤�ȣ���Ҫ�ֶ�ɾ��it1��ar + n��Ԫ��
	cout << "ȥ�ؽ����" << endl;
	for_each(ar, it1, show);
	cout << endl;

	for (auto it = ar; it != it1; it++)
	{
		
		temp++;
	}
	
	



	return temp;
}


void show(const long& lo)
{

	cout << lo << " ";
}