#include<iostream>

using std::cout;
using std::endl;
using std::cin;


int main()
{


	int a = 0;
	int b = 0;
	
	cout << "请输入两个整数: " << endl;
	cin >> a >> b;

	if (a > b)
	{
		cout << b << " 和 " << a << " 之间的所有整数是: ";
		while (b <= a)
		{
			cout << b << " ";
			b++;
		}

	}
	else if (a < b)
	{
		cout << a << " 和 " << b << " 之间的所有整数是: ";

		while (a <= b)
		{
			cout << a << " ";
			a++;
		}


	}
	else
	{
		cout << "输入的两个整数相同！值为:";
		cout << a;

	}

	cout << endl;


	system("pause");
	return 0;
}