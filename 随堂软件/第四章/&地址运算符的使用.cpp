#include <iostream>           //&地址运算符的使用
int main()
{
	using namespace std;
	int donuts = 6;
	double cups = 4.5;

	cout << "donuts balue = " << donuts;
	cout << " and donuts address = " << &donuts << endl;
	cout << "cups balue = " << cups;
	cout << " and cups address = " << &cups << endl;
	cin.get();
	cin.get();
	return 0;
}
