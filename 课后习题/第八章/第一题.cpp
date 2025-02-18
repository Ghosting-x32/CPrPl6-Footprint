#include<iostream>
#include<cstdlib>
using namespace std;
inline void f1(const char* pn, int n = 1)
{
	if (n == 0) 
	{
		cout << "你的形参n的实参为0，程序将退出！\a\a\n";
		system("pause");
		exit(0);
	}
	else
		cout << pn << endl;
}

int main()
{
	const char* ps = "hahhahah";
	f1(ps);
	f1(ps, 0);


	cout << endl;
	system("pause");
	return 0;
}

