#include<iostream>
#include<string>


using namespace std;

int main()
{
	int temperature = 63;
	cout << "Today's water temperature: ";
	cout.setf(ios_base::showpos);//在正数前面加上+
	cout << temperature << endl;
	
	cout << "For out programming friends, that's\n";
	cout << hex << temperature << endl;//16进制
	cout.setf(ios_base::uppercase);//对于16进制输出，使用大写字母
	cout.setf(ios_base::showbase);//对于输出，使用C++基数前缀（0， 0x）
	cout << "or\n";
	cout << temperature << endl;

	cout << "How " << true << "! oops -- How ";
	cout.setf(ios_base::boolalpha);//输入和输出bool值，可以为true或false
	cout << true << "!\n";












	system("pause");
	return 0;
}