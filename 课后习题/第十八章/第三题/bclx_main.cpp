#include <iostream>
#include<string>
#include"boost/lexical_cast.hpp"//实现字符串与数值之间的转换

using namespace std;

template<typename T>
long double sum_value(const T& value);

template<typename T, typename... Arges>//可变参数模板函数
long double sum_value(const T& value, const Arges&... arge);



int main()
{

	cout << sum_value(10, 20.22, 'A', 30L, 62.33f, 50LL, 82.36L) << endl;


	system("pause");
	return 0;
}


template<typename T, typename... Arges>//可变参数模板函数
long double sum_value(const T& value, const Arges&... arge)
{
	
	return  (long double)value + sum_value(arge...);//递归计算

}


template<typename T>//递归到函数参数包只有一个数据时走这个函数模板，并结束递归
long double sum_value(const T& value)
{
	return (long double)value;
}