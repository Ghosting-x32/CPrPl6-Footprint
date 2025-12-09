#include<iostream>


using std::cin;
using std::endl;

int main()
{
	int i = 0;
	cin >> i;
//	cout << i;错误，没有对应的using声明，必须使用完整的名字
	std::cout << i;
	
	 
	std::cout << endl;

	system("pause");
	return 0;
}