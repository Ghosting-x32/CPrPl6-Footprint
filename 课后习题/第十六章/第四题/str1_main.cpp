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
	//静态数组无法删除元素，只能做逻辑上的删除---不访问后面需要删除的元素
	int a = reduce(arlo, 8);
	cout << "排序去重后的arlo元素数目为：" << a << endl;
	cout << "排序去重后的arlo数组内容为：" << endl;
	for_each(arlo, arlo + a, show);//逻辑上的删除
	cout << endl;
	


	system("pause");
	return 0;
}


int reduce(long ar[], int n)
{
	int temp = 0;
	sort(ar, ar + n);
	cout << "排序结果：" << endl;
	for_each(ar, ar + n, show);
	cout << endl;

	auto it1 = unique(ar, ar + n);//算法unique删除迭代器区间内重复的元素，返回去重后区间最后的位置--返回一个超尾
	//去重后unique只是算法，不能自动调整数组长度，需要手动删除it1到ar + n的元素
	cout << "去重结果：" << endl;
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