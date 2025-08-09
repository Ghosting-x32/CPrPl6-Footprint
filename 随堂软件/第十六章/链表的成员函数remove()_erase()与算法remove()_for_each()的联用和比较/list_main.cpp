#include<iostream>
#include<string>
#include<algorithm>
#include<list>


using namespace std;

void Show(int v);

const int LIM = 10;

int main()
{
	int ar[LIM] = { 4, 5, 4, 2, 2, 3, 4, 8, 1, 4 };
	list<int> la(ar, ar + LIM);
	list<int> lb(la);
	cout << "Original list contents:\n\t";
	for_each(la.begin(), la.end(), Show);
	cout << endl;
	la.remove(4);//ʹ��STL���������Ƴ�----�����ĳ�Ա����������ʹ�ã�
	//�Զ����������ڴ�
	cout << "After using the remove() method:\n";
	cout << "la:\t";
	for_each(la.begin(), la.end(), Show);
	cout << endl;

	list<int>::iterator last;
	//��ȥ����ʣ���Ԫ����ǰ�ƶ��������µĳ�β������
	last = remove(lb.begin(), lb.end(), 4);//ʹ��STL���������Ƴ�----�㷨
	//��Ҫ�ֶ����������ڴ�
	cout << "After using the remove() function:\n";
	cout << "lb:\t";
	for_each(lb.begin(), lb.end(), Show);//���Կ��������ڴ�û�иı䣬�µĳ�β���滹��û�õ�Ԫ�أ���Ҫ�ֶ�ɾ��
	cout << endl;
	cout << "lb�³�β:\t";
	for_each(lb.begin(), last, Show);
	cout << endl;

	lb.erase(last, lb.end());//ɾ�������һ������---Ԫ���������õ�����
	//�ֶ����������ڴ�
	cout << "After using the erase() method:\n";
	cout << "lb:\t";
	for_each(lb.begin(), lb.end(), Show);//���Կ��������ڴ�û�иı䣬�µĳ�β���滹��û�õ�Ԫ�أ���Ҫ�ֶ�ɾ��
	cout << endl;




	system("pause");
	return 0;
}


void Show(int v)
{

	cout << v << " ";
}
