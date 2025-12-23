#include<iostream>
#include<vector>
#include<string>
#include<iterator>
#include<cstddef>
#include<cctype>






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



int compare(const int val, const int* p);




int main()
{
	/*
通过分析题意我们知道，函数实际上比较的是第一个实参的值和第二个实参所
指数组首元素的值。因为两个参数的内容都不会被修改，所以指针的类型应该是
const int*。


*/

	int a1 = 100;
	int a2 = 100;
	int* p2 = &a2;

	int result = compare(a1, p2);

	cout << "较大的值是: " << result << endl;
	








	system("pause");
	return 0;
}

int compare(const int val, const int* p)
{
	int temp = 0;

	if (val > *p)
	{
		temp = val;
	}
	else if(val < *p)
	{
		temp = *p;
	}
	else
	{
		temp = val;
		cout << "两个一样大,均为: " << temp << endl;
	}



	return temp;
}
