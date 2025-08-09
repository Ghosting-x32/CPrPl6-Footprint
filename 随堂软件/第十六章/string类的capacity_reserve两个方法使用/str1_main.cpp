#include<iostream>
#include<string>


using namespace std;



int main()
{
	string empty;
	string small = "bit";
	string larger = "Elephants are a girl's best friend";

	cout << "Sizes:\n";
	cout << "\tempty: " << empty.size() << endl;
	cout << "\tsmall: " << small.size() << endl;
	cout << "\tlarger: " << larger.size() << endl;

	cout << "Capacities:\n";
	cout << "\tempty: " << empty.capacity() << endl;//返回当前分配给字符串的内存块大小
	cout << "\tsmall: " << small.capacity() << endl;
	cout << "\tlarger: " << larger.capacity() << endl;

	empty.reserve(50);//请求内存块的最小长度
	cout << "Capacity after empty.reserve(50): " << empty.capacity() << endl;


	system("pause");
	return 0;
}