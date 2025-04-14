#include <iostream>

int main()
{
	using namespace std;

	short num1 = 10;
	int num2 = 10;
	long num3 = 10;
	long long num4 = 10;

	cout << "short 所占内存：" << sizeof(num1) << " 字节B" << endl;
	cout << "int 所占内存：" << sizeof(num2) << " 字节B" << endl;
	cout << "long 所占内存：" << sizeof(num3) << " 字节B" << endl;
	cout << "long long 所占内存：" << sizeof(num4) << " 字节B" << endl;

	
	system("pause");
	return 0;
}


