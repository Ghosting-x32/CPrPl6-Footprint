#include<iostream>
#include<string>
#include<algorithm>
#include<iterator>

using namespace std;

template<typename T>
int reduce(T ar[], int n);

template<typename T>
void show(const T& lo);

int main()
{
	long arlo[8] = { 3, 6, 9, 2, 5, 6, 5, 1 };
	//��̬�����޷�ɾ��Ԫ�أ�ֻ�����߼��ϵ�ɾ��---�����ʺ�����Ҫɾ����Ԫ��
	int a = reduce(arlo, 8);//ģ�庯���Զ������Ƶ���int a = reduce<long>(arlo, 8);--��ʾ����
	cout << "����ȥ�غ��arloԪ����ĿΪ��" << a << endl;
	cout << "����ȥ�غ��arlo��������Ϊ��" << endl;
	for_each(arlo, arlo + a, show<long>);//�߼��ϵ�ɾ��
	cout << endl;
	


	system("pause");
	return 0;
}


template<typename T>
int reduce(T ar[], int n)
{
	int temp = 0;
	sort(ar, ar + n);
	cout << "��������" << endl;
	for_each(ar, ar + n, show<T>);
	cout << endl;

	auto it1 = unique(ar, ar + n);//�㷨uniqueɾ���������������ظ���Ԫ�أ�����ȥ�غ���������λ��--����һ����β
	//ȥ�غ�uniqueֻ���㷨�������Զ��������鳤�ȣ���Ҫ�ֶ�ɾ��it1��ar + n��Ԫ��
	cout << "ȥ�ؽ����" << endl;
	for_each(ar, it1, show<T>);
	cout << endl;

	for (auto it = ar; it != it1; it++)
	{
		
		temp++;
	}
	
	



	return temp;
}


template<typename T>
void show(const T& lo)
{

	cout << lo << " ";
}