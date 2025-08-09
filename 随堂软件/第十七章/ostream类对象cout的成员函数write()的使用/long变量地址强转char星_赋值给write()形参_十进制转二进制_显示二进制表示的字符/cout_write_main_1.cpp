#include<iostream>
#include<string>
#include<cstring>

using namespace std;

int main()
{
	

	long val = 560031841;//00100001 01100001 01101000 01100001
	//                       !          a        h        a
	cout << &val << endl;//000000360258FB14--16进制每一次运行都不同
	cout << (char*)&val << endl;
	cout.write((char*)&val, sizeof(long)) << endl;
	//传输内存中储存的位表示
	//十进制强制转换为二进制地址--传输二进制表示的字符（附录C ASCII 字符集）


	system("pause");
	return 0;
}