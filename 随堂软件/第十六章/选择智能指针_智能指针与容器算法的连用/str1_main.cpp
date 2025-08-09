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

	for_each(vp.begin(), vp.end(), show);//用普通函数给算法提供遍历后要做的动作提供方法
	cout << endl;
	for_each(vp.begin(), vp.end(), text());//用仿函数给算法提供遍历后要做的动作提供方法
	//text()匿名函数对象---匿名类对象
	cout << endl;
	text text1;

	for_each(vp.begin(), vp.end(), text1);//text1有名函数对象---有名类对象
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