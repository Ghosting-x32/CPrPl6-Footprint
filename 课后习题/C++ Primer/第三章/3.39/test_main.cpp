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




int main()
{
	string str1 = "aaa";
	string str2 = "bbb";

	if (str1 >= str2)
	{
		cout << str1 << endl;
	}
	else
	{
		cout << str2 << endl;
	}

	char arr1[] = "aaa";
	char arr2[] = "bbb";

	if (strcmp(arr1, arr2) >= 0)
	{
		cout << arr1 << endl;
	}
	else
	{
		cout << arr2 << endl;
	}

	
	


	system("pause");
	return 0;
}