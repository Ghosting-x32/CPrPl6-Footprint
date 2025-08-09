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

	three.remove(2);//1.删除链表中所有的元素2
	cout << endl << "List three minus 2s: ";
	for_each(three.begin(), three.end(), outint);

	three.splice(three.begin(), one);//2.将链表one插入链表three的头部，届时one链表变为空
	cout << endl << "List three after splice: ";
	for_each(three.begin(), three.end(), outint);
	cout << endl << "List one: ";
	for_each(one.begin(), one.end(), outint);

	three.unique();//3.将连续的相同元素压缩为单个元素
	cout << endl << "List three after unique: ";
	for_each(three.begin(), three.end(), outint);

	three.sort();
	three.unique();//4.对链表three排序之后再压缩连续的相同元素为单个元素
	cout << endl << "List three after sort & unique: ";
	for_each(three.begin(), three.end(), outint);

	two.sort();
	three.merge(two);//5.将链表three与链表two合并，届时two将变为空,two合并到了three
	//必须确保两个链表已经排序，才能使用该函数
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