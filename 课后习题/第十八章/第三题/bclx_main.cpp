#include <iostream>
#include<string>
#include"boost/lexical_cast.hpp"//ʵ���ַ�������ֵ֮���ת��

using namespace std;

template<typename T>
long double sum_value(const T& value);

template<typename T, typename... Arges>//�ɱ����ģ�庯��
long double sum_value(const T& value, const Arges&... arge);



int main()
{

	cout << sum_value(10, 20.22, 'A', 30L, 62.33f, 50LL, 82.36L) << endl;


	system("pause");
	return 0;
}


template<typename T, typename... Arges>//�ɱ����ģ�庯��
long double sum_value(const T& value, const Arges&... arge)
{
	
	return  (long double)value + sum_value(arge...);//�ݹ����

}


template<typename T>//�ݹ鵽����������ֻ��һ������ʱ���������ģ�壬�������ݹ�
long double sum_value(const T& value)
{
	return (long double)value;
}