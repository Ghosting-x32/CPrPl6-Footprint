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
	la.remove(4);//使用STL方法进行移除----容器的成员函数（优先使用）
	//自动调整容器内存
	cout << "After using the remove() method:\n";
	cout << "la:\t";
	for_each(la.begin(), la.end(), Show);
	cout << endl;

	list<int>::iterator last;
	//把去除后剩余的元素向前移动，返回新的超尾迭代器
	last = remove(lb.begin(), lb.end(), 4);//使用STL函数进行移除----算法
	//需要手动调整容器内存
	cout << "After using the remove() function:\n";
	cout << "lb:\t";
	for_each(lb.begin(), lb.end(), Show);//可以看出链表内存没有改变，新的超尾后面还有没用的元素，需要手动删除
	cout << endl;
	cout << "lb新超尾:\t";
	for_each(lb.begin(), last, Show);
	cout << endl;

	lb.erase(last, lb.end());//删除链表的一个区间---元素内容无用的区间
	//手动调整容器内存
	cout << "After using the erase() method:\n";
	cout << "lb:\t";
	for_each(lb.begin(), lb.end(), Show);//可以看出链表内存没有改变，新的超尾后面还有没用的元素，需要手动删除
	cout << endl;




	system("pause");
	return 0;
}


void Show(int v)
{

	cout << v << " ";
}
