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
	cout << "\tempty: " << empty.capacity() << endl;//���ص�ǰ������ַ������ڴ���С
	cout << "\tsmall: " << small.capacity() << endl;
	cout << "\tlarger: " << larger.capacity() << endl;

	empty.reserve(50);//�����ڴ�����С����
	cout << "Capacity after empty.reserve(50): " << empty.capacity() << endl;


	system("pause");
	return 0;
}