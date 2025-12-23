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
	
	int j = fact(-5);
	
	cout << "-5的绝对值是: " << j << endl;


	system("pause");
	return 0;
}



int fact(int val)
{
	int ret = 0;
	if (val >= 0)
	{
		ret = val;
	}
	else
	{
		ret = -val;
	}

	return ret;
}