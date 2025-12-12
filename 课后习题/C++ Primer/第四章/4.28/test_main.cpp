#include<iostream>
#include<vector>
#include<string>
#include<cctype>
#include<iterator>
#include<cstddef>
#include<typeinfo>
#include<cstring>                  




using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::begin;
using std::end;
using std::size_t;
using std::ptrdiff_t;
using std::strlen;




int main()
{
	cout << "bool:\t\t" << sizeof(bool) << endl;


	cout << "char:\t\t" << sizeof(char) << endl;
	cout << "unsigned char:\t\t" << sizeof(unsigned char) << endl;
	cout << "signed char:\t\t" << sizeof(signed char) << endl;

	cout << "wchar_t:\t\t" << sizeof(wchar_t) << endl;
	
	cout << "char16_t:\t\t" << sizeof(char16_t) << endl;

	cout << "char32_t:\t\t" << sizeof(char32_t) << endl;


	cout << "short:\t\t" << sizeof(short) << endl;
	cout << "int:\t\t" << sizeof(int) << endl;
	cout << "long:\t\t" << sizeof(long) << endl;
	cout << "long long:\t\t" << sizeof(long long) << endl;

	cout << "float:\t\t" << sizeof(float) << endl;
	cout << "double:\t\t" << sizeof(double) << endl;
	cout << "long double:\t\t" << sizeof(long double) << endl;

	cout << "unsigned short:\t\t" << sizeof(unsigned short) << endl;
	cout << "unsigned int:\t\t" << sizeof(unsigned int) << endl;
	cout << "unsigned long:\t\t" << sizeof(unsigned long) << endl;
	cout << "unsigned long long:\t\t" << sizeof(unsigned long long) << endl;




	system("pause");
	return 0;
}