#include <iostream>//语句块中的变量
int main()
{
	using namespace std;
	int x = 20;
	{
		int y = 100;
		cout << x << endl;
		cout << y << endl;
	}
	cout << x << endl;//语句块中声明外部声明的变量可用
	cout << y << endl;//语句块中声明外部没有声明的变量不可用
	cin.get();
	cin.get();
	return 0;
}
