#include<iostream>
int main()
{
	using namespace std;
		int i, j, a;
		cout << "请输入较小的数：";
		cin >> i;
		cout << "请输入较大的数：";
		cin >> j;
		for (a=i;i<j;++i)
			a = (i + 1) + a;
		cout << "总和是：" << a;

	cin.get();
	cin.get();
	return 0;
}