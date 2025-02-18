#include<iostream>
#include"plorg.h"


int main()
{
	using namespace std;
	Plorg moren;
	cout << "默认类对象(moren)内容是：" << endl;
	moren.show();
	cout << endl;
	Plorg one = Plorg("haodongxi", 100);
	cout << "类对象one的内容是：" << endl;
	one.show();
	cout << endl;
	one.gnexi(300);
	cout << "one更新后的内容是：" << endl;
	one.show();











	system("pause");
	return 0;
}
