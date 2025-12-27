#pragma once
#include<string>


using std::string;



struct Person
{
	string name_n;
	string address_a;

	/*
	上述两个函数应该被定义成常量成员函数，因为不论返回姓名还是返回地址，
在函数体内都只是读取数据成员的值，而不会做任何改变。
	
	*/
	string rt_name()const;
	string rt_address()const;




};