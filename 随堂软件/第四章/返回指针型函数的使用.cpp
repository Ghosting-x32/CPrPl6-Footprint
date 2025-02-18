#include <iostream>           //返回指针型函数的使用(为使用巨大字符串节省内存）
#include<cstring>
using namespace std;
char* getname(void);

int main()
{
	char* name;

	name = getname();
	cout << name << " at " << (int*)name << "\n";
	delete[] name;

	name = getname();
	cout << name << " at " << (int*)name << "\n";
	delete[] name;

	cin.get();
	cin.get();
	return 0;
}

char* getname()
{
	char temp[80];
	cout << "Enter last name: ";
	cin.getline(temp, 80);
	char* pn = new char[strlen(temp) + 1];
	strcpy_s(pn, strlen(temp) + 1, temp);

	return pn;
}