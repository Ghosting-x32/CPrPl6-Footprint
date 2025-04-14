#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

void test01();
void myprint(int val);


int main()
{
	test01();


	system("pause");
	return 0;
}

void myprint(int val)
{
	cout << val << " ";
}

void test01()
{
	vector<int>v1;
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);

	vector<int>v2;
	for (int i = 12; i < 17; i++)
	{
		v2.push_back(i);
	}

	vector<int>v3;
	for (int i = 20; i < 30; i = i + 2)
	{
		v3.push_back(i);
	}

	//1.循环遍历
	vector<int>::iterator pBegin = v1.begin();
	vector<int>::iterator pEnd = v1.end();

	while (pBegin != pEnd)
	{
		cout << *pBegin << " ";
		pBegin++;
	}
	cout << endl;

	//2.循环遍历2
	for (vector<int>::iterator it = v2.begin(); it != v2.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	//vector<int>::iterator pBegin3 = v3.begin();
	//vector<int>::iterator pEnd3 = v3.end();
	//3.使用算法遍历
	for_each(v3.begin(), v3.end(), myprint);
	cout << endl;

}

