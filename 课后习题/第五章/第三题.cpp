#include<iostream>
int main()
{
	using namespace std;
	cout << "请输入你的第一个数字：";
	int i;
	int j;
	do
	{
		cin >> i;
		cout << "输入的累计和是：" << i << endl;
		j = 1;
		while ((i * j) != 0)
		{
			cout << "请输入你的下一个数字：";
			cin >> j;
			i = i + j;
			cout << "输入的累计和是：" << i << endl;
		}
	} while ((i * j) != 0);


	cin.get();
	cin.get();
	return 0;
}