#include<iostream>
#include<vector>
#include<string>
#include<cctype>



using std::cin;
using std::cout;
using std::endl;
using std::vector;    
using std::string;


// 定义在全局作用域中的数组
string sa[10];
int ia[10];

int main()
{
	
	// 定义在局部作用域中的数组
	string sa2[10];
	int ia2[10];
	for (auto c : sa)
		cout << c << "*";
	cout << endl;
	for (auto c : ia)
		cout << c << "*";
	cout << endl;
	for (auto c : sa2)
		cout << c << "*";
	cout << endl;
	for (auto c : ia2)
		cout << c << "*";
	cout << endl;

	char ia3[] = "hhh";
	cout << strlen(ia3) << endl;

	int ia4[] = { 1, 2, 3, 4, 5 };
	cout << sizeof(ia4) / sizeof(ia4[0]) << endl;


	system("pause");
	return 0;
}