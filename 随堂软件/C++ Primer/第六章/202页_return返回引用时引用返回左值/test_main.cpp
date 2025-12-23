#include<iostream>
#include<vector>
#include<string>
#include<iterator>
#include<cstddef>
#include<cctype>
#include<initializer_list>






using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::begin;
using std::end;
using std::size_t;
using std::isupper;
using std::tolower;
using std::initializer_list;


char& get_valll(string& str, string::size_type ix);




int main()
{
	string s("a value");
	cout << s << endl;
	get_valll(s, 0) = 'A';
	cout << s << endl;


	system("pause");
	return 0;
}




char& get_valll(string& str, string::size_type ix)
{


	return str[ix];
}