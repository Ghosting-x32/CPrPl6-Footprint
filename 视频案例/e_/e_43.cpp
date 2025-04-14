#include<iostream>
#include<string>
#include<deque>
#include<algorithm>



using namespace std;

void test01();
void printIntDeque(const deque<int>& d1);




int main()
{
	test01();


	system("pause");
	return 0;
}



void test01()
{
	deque<int>d1;
	d1.push_back(10);
	d1.push_back(20);
	d1.push_back(30);
	d1.push_front(100);
	d1.push_front(200);
	d1.push_front(300);

	cout << "排序前的数组：" << endl;
	printIntDeque(d1);

	sort(d1.begin(), d1.end());//默认是升序排序
	cout << "排序后的数组：" << endl;
	printIntDeque(d1);


}

void printIntDeque(const deque<int>& d1)
{
	for (deque<int>::const_iterator it = d1.begin(); it != d1.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}