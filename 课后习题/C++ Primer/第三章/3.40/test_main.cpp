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
using std::strlen;




int main()
{
	//char str1[] = "Welcome to ";
	//char str2[] = "C++ family!";
	//// 利用strlen 函数计算两个字符串的长度，并求得结果字符串的长度
	//char result[strlen(str1) + strlen(str2) - 1];//strlen(str1) + strlen(str2) - 1是程序运行时才能计算出来的值，不是常量表达式
	// 数组的维度必须是常量表达式：值不能改变，而且在编译阶段就能计算出值
	//strcpy(result, str1); // 把第一个字符串拷贝到结果字符串中
	//strcat(result, str2); // 把第二个字符串拼接到结果字符串中
	//cout << "第一个字符串是：" << str1 << endl;
	//cout << "第二个字符串是：" << str2 << endl;
	//cout << "拼接后的字符串是：" << result << endl;


	

	char str1[] = "Welcome to ";
	char str2[] = "C++ family!";
	// 利用strlen 函数计算两个字符串的长度，并求得结果字符串的长度
	char result[50];
	strcpy_s(result, str1); // 把第一个字符串拷贝到结果字符串中
	strcat_s(result, str2); // 把第二个字符串拼接到结果字符串中
	cout << "第一个字符串是：" << str1 << endl;
	cout << "第二个字符串是：" << str2 << endl;
	cout << "拼接后的字符串是：" << result << endl;
	int a = strlen(str1) + strlen(str2);
	cout << a << endl;


	char arr1[] = "aaa";
	char arr2[] = "bbb";
	char arr3[7] = {};

	
	
	strcpy_s(arr3, arr1);
	cout << arr3 << endl;
	strcat_s(arr3, arr2);	
	cout << arr3 << endl;

	system("pause");
	return 0;
}