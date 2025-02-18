#include <iostream>//cin.get()弥补char数组的缺陷(混合输入数字和面向行的字符串会导致问题）
int main()
{
	using namespace std;
	cout << "What year was your house built?\n";
	int year;
	cin >> year;
	cin.get();
	cout << "What is its street address?\n";
	char address[80];
	cin.getline(address, 80);
	cout << "Year built:" << year << endl;
	cout << "Address: " << address << endl;
	cout << "Done!\n";
	cin.get();
	cin.get();
	return 0;
}
