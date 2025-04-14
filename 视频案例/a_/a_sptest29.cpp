#include <iostream>

int main()
{
	using namespace std;
	int a = 10;
	int b = 20;
	int c = 0;
	c = (a > b ? a : b);//如果a>b为真则返回a，为假则返回b
	cout << "c = " << c << endl;
	a > b ? a : b = 100;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	c = (a < b ? a : b);
	cout << "c = " << c << endl;


	system("pause");
	return 0;
}


