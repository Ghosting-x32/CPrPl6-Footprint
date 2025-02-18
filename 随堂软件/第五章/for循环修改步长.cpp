#include <iostream>//for循环修改步长
int main()
{
	using namespace std;
	cout << "Enter an integer: ";
	int by;
	cin >> by;
	cout << "Counting by " << by << "s:\n";
	for (int i = 0; i < 100; i = i + by)
		cout << i << endl;
	cin.get();
	cin.get();
	return 0;
}
