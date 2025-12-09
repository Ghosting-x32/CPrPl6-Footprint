 #include<iostream>
#include<string>


using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
	//1.一次读入一整行
	string str1;
	getline(cin, str1);

	cout << str1 << endl;







	//2.一次读入一个词

	string str2;
	cin >> str2;
	cout << str2 << endl;


	system("pause");
	return 0;
}