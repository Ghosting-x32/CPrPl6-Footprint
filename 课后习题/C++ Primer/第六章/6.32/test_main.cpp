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



int& get(int* arry, int index);
/*
该函数是合法的。get 函数接受一个整型指针，该指针实际指向一个整型数组
的首元素，另外还接受一个整数表示数组中某个元素的索引值。它的返回值类型是
整型引用，引用的对象是arry 数组的某个元素。当get 函数执行完毕后，调用者
得到实参数组arry 中索引为index 的元素的引用。
在 main 函数中，首先创建一个包含10 个整数的数组，名字是ia。请注意，由
于ia 定义在main 函数的内部，所以ia 不会执行默认初始化操作，如果此时我们
直接输出ia 每个元素的值，则这些值都是未定义的。接下来进入循环，每次循环使
用get 函数得到数组ia 中第i 个元素的引用，为该引用赋值i，也就是说，为第i
个元素赋值i。循环结束时，ia 的元素依次被赋值为0～9。



*/



int main()
{
	int ia[10] = {};
	cout << "调用get()函数之前ia的元素是:" << endl;
	for (auto& c : ia)
	{
		cout << c << " ";
	}
	cout << endl;

	for (int i = 0; i != 10; ++i)
	{
		get(ia, i) = i;
	}

	cout << "调用get()函数之后ia的元素是:" << endl;
	for (auto& c : ia)
	{
		cout << c << " ";
	}

	cout << endl;



	system("pause");
	return 0;

}


int& get(int* arry, int index)
{

	return arry[index];

}



