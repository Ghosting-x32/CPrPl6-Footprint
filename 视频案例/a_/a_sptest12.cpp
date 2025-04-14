#include <iostream>

int main()
{
	using namespace std;
	//转义字符:换行符（\n）,一个\(\\）
	//水平制表符（\t）-----满8个字符跳到下一个tab位置(向前数总共占8个字符位置)
	cout << "hello world!\n";
	cout << "\\" << endl;
	cout << "aa\tbbb" << endl;
	cout << "aaaa\tbbb" << endl;
	cout << "aaaaaaaa\tbbb" << endl;
	cout << "aaaaaaaaa\tbbb" << endl;
	cout << "aaaaaaaaaa\tbbb" << endl;


	
	system("pause");
	return 0;
}


