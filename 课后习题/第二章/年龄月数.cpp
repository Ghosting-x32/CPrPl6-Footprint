#include <iostream>
int main()
{
	using namespace std;          //A表示年龄，B表示包含月数。
	cout << "Enter your age: ";
	int A;
	cin >> A;
	cout << "Your age in months is ";
	int B;
	B = A * 12;
	cout << B << ".";
	cin.get();
	cin.get();
	return 0;
}