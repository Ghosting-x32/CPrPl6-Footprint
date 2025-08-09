#include<iostream>
#include<string>
#include<algorithm>
#include<iterator>
#include<list>



using namespace std;

void outint(int n);

int main()
{
	list<int> one(5, 2);
	int stuff[5] = { 1,2,4,8,6 };
	list<int> two;
	two.insert(two.begin(), stuff, stuff + 5);
	int more[6] = { 6,4,2,4,6,5 };
	list<int> three(two);
	three.insert(three.end(), more, more + 6);

	cout << "List one: ";
	for_each(one.begin(), one.end(), outint);

	cout << endl << "List two: ";
	for_each(two.begin(), two.end(), outint);

	cout << endl << "List three: ";
	for_each(three.begin(), three.end(), outint);

	three.remove(2);//1.ɾ�����������е�Ԫ��2
	cout << endl << "List three minus 2s: ";
	for_each(three.begin(), three.end(), outint);

	three.splice(three.begin(), one);//2.������one��������three��ͷ������ʱone�����Ϊ��
	cout << endl << "List three after splice: ";
	for_each(three.begin(), three.end(), outint);
	cout << endl << "List one: ";
	for_each(one.begin(), one.end(), outint);

	three.unique();//3.����������ͬԪ��ѹ��Ϊ����Ԫ��
	cout << endl << "List three after unique: ";
	for_each(three.begin(), three.end(), outint);

	three.sort();
	three.unique();//4.������three����֮����ѹ����������ͬԪ��Ϊ����Ԫ��
	cout << endl << "List three after sort & unique: ";
	for_each(three.begin(), three.end(), outint);

	two.sort();
	three.merge(two);//5.������three������two�ϲ�����ʱtwo����Ϊ��,two�ϲ�����three
	//����ȷ�����������Ѿ����򣬲���ʹ�øú���
	cout << endl << "Sorted two merged int three: ";
	for_each(three.begin(), three.end(), outint);
	cout << endl << "List two: ";
	for_each(two.begin(), two.end(), outint);
	cout << endl;

	

	system("pause");
	return 0;
}


void outint(int n)
{
	cout << n << " ";

}