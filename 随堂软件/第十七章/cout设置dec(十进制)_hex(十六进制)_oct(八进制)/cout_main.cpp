#include<iostream>
#include<string>


using namespace std;

int main()
{
	cout << "Enter an integer: ";
	int n;
	cin >> n;
	cout << "n n*n\n";
	cout << n << " " << n * n << " (decimal)\n";//10����
	
	cout << hex;
	cout << n << " " << n * n << " (hexadecimal)\n";//16����

	cout << oct << n << " " << n * n << " (octal)\n";//8����

	dec(cout);//������ʽ����
	cout << n << " " << n * n << " (decimal)\n";//10����
	


	system("pause");
	return 0;
}