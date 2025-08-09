#include<iostream>
#include<string>
#include<memory>
#include<vector>
#include<algorithm>
#include<random>

#include"text.h"

using namespace std;

unique_ptr<int> make_int(int n);
void show(unique_ptr<int>& pi);

int main()
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dis1(0, 1000);

	int size = 5;
	vector<unique_ptr<int>> vp(size);
	for (int i = 0; i < vp.size(); i++)
	{
		vp[i] = make_int(dis1(gen));
	}

	cout << "vp.size(): " << vp.size() << endl;
	vp.push_back(make_int(dis1(gen)));

	cout << "vp.size(): " << vp.size() << endl;

	vp.push_back(make_int(dis1(gen)));

	cout << "vp.size(): " << vp.size() << endl;

	for_each(vp.begin(), vp.end(), show);//����ͨ�������㷨�ṩ������Ҫ���Ķ����ṩ����
	cout << endl;
	for_each(vp.begin(), vp.end(), text());//�÷º������㷨�ṩ������Ҫ���Ķ����ṩ����
	//text()������������---���������
	cout << endl;
	text text1;

	for_each(vp.begin(), vp.end(), text1);//text1������������---���������
	cout << endl;



	system("pause");
	return 0;
}


unique_ptr<int> make_int(int n)
{
	return unique_ptr<int>(new int(n));

}


void show(unique_ptr<int>& pi)
{
	cout << *pi << " ";

}