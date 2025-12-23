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



void reset(int& i);




int main()
{
	int val = 200;

	cout << "修改前val的值: " << val << endl;

	reset(val);

	cout << "修改后val的值: " << val << endl;






	system("pause");
	return 0;
}


void reset(int& i)
{

	i = 0;


}

