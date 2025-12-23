#include<iostream>
#include<vector>
#include<string>
#include<iterator>
#include<cstddef>






using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::begin;
using std::end;
using std::size_t;




int fact(int val);


int main()
{
	
	int j = fact(2);
	
	cout << "5! is " << j << endl;


	system("pause");
	return 0;
}



int fact(int val)
{
	int ret = 1;
	while (val >= 1)
	{
		ret *= val--;
	}

	return ret;
}