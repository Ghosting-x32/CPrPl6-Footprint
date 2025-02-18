#include <iostream>  
#include<string>
int main()
{
	using namespace std;
	cout << "Enter your first name: ";
	string str1;
	string str2;
	getline(cin, str1);
	cout << "Enter your last name: ";
	getline(cin, str2);
	cout << "Here's the information in a single string: ";
	string str3  = ", ";

	string qn1;
	string qn2;
	string qn3;

	qn1 = str1;
	qn2 = str2;
	qn3 = str3;

	cout<< qn1 + qn3 + qn2 << endl;
	cin.get();
	cin.get();
	return 0;
}
