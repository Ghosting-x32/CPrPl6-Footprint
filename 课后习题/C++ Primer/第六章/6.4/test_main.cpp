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




int fact();


int main()
{
	
	int j = fact();
	
	cout << "阶乘结果是: " << j << endl;


	system("pause");
	return 0;
}



int fact()
{
	int ret = 1;
	int val = 1;
	cout << "请输入一个整数，用于求它的阶乘:" << endl;
	cin >> val;
	while (val >= 1)
	{
		ret *= val--;
	}

	return ret;
}