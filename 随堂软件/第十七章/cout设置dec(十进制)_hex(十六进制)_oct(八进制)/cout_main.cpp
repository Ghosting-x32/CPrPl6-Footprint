#include<iostream>
#include<string>


using namespace std;

int main()
{
	cout << "Enter an integer: ";
	int n;
	cin >> n;
	cout << "n n*n\n";
	cout << n << " " << n * n << " (decimal)\n";//10进制
	
	cout << hex;
	cout << n << " " << n * n << " (hexadecimal)\n";//16进制

	cout << oct << n << " " << n * n << " (octal)\n";//8进制

	dec(cout);//函数形式调用
	cout << n << " " << n * n << " (decimal)\n";//10进制
	


	system("pause");
	return 0;
}