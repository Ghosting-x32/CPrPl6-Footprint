#include<iostream>





using namespace std;



int main()
{
	int num1 = 0;
	char ch;
	cout << "请输入一些字符：" << endl;
	while (cin.get(ch) && ch != '$')
	{
		num1++;
		cout << ch;
	}
	cout << "\n$之前的字符数是：" << num1 << endl;

	cin.putback(ch);
	char ch1;
	cin.get(ch1);
	cout << "输入流的下一个字符是：" << ch1 << endl;
	cout << "后面的字符是：" << endl;
	while (cin.get(ch1))//键盘模拟文件尾结束循环【ctrl+Z】
	{

		cout << ch1;
	}

	system("pause");
	return 0;
}