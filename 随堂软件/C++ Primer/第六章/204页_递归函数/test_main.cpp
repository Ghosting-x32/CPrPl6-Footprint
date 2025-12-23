#include<iostream>
#include<vector>
#include<string>
#include<iterator>
#include<cstddef>
#include<cctype>
#include<initializer_list>
#include<cstdlib>






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



int factorial(int val);



int main()
{

	cout << "5! = " << factorial(5) << endl;


	system("pause");
	return 0;

}

int factorial(int val)
{
	if (val > 1)
	{
		return factorial(val - 1)* val;
	}

	return 1;

}




