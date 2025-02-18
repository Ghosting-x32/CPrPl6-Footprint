#include<iostream>
#include"move.h"


int main()
{
	using namespace std;
	Move one = Move(3.6, 4.8);
	cout << "类对象one的内容是：" << endl;
	one.showmove();
	cout << endl;
	Move two(8.8, 9.2);
	cout << "类对象two的内容是：" << endl;
	two.showmove();
	cout << endl;
	Move csot = one.add(two);
	cout << "类对象csot(one与two的合并)的内容是：" << endl;
	csot.showmove();
	cout << endl;
	csot.reset(2.2, 3.3);
	cout << "类对象csot(重置后)的内容是：" << endl;
	csot.showmove();













	system("pause");
	return 0;
}
