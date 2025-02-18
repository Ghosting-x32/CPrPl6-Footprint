#include<iostream>
template<typename T>
void swapr(T& a, T& b);



int main()
{
	using namespace std;
	int i = 10;
	int j = 20;
	cout << "i, j = " << i << ", " << j << ".\n";
	cout << "Using compiler-generated int swapper:\n";
	swapr(i, j);
	cout << "Now i, j = " << i << ", " << j << ".\n";

	double x = 24.5;
	double y = 81.7;
	cout << "x, y = " << x << ", " << y << ".\n";
	cout << "Using compiler-generated double swapper:\n";
	swapr(x, y);
	cout << "Now x, y = " << x << ", " << y << ".\n";

	char x1 = 'a';
	char y1 = 'b';
	cout << "x1, y1 = " << x1 << ", " << y1 << ".\n";
	cout << "Using compiler-generated char swapper:\n";
	swapr(x1, y1);
	cout << "Now x1, y1 = " << x1 << ", " << y1 << ".\n";


	system("pause");
	return 0;
}

template<typename T>
void swapr(T& a, T& b)
{
	T temp;
	temp = a;
	a = b;
	b = temp;
}
