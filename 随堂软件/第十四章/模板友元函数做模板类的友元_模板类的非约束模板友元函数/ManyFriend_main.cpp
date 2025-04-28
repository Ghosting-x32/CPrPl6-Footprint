#include<iostream>
#include<string>


#include"ManyFriend.h"


using namespace std;



int main()
{
	

	ManyFriend<int>hfi1(10);
	ManyFriend<int>hfi2(20);
	ManyFriend<double>hfdb(10.5);
	
	
	
	
	cout << "hfi1, hfi2: ";
	show2(hfi1, hfi2);//函数模板的调用---自动类型推导
	cout << "hfi1, hfdb: ";
	show2<>(hfi1, hfdb);//函数模板的调用---自动类型推导
	cout << "hfi2, hfdb: ";
	show2<ManyFriend<int>, ManyFriend<double>>(hfi2, hfdb);//函数模板的调用---显示类型




	system("pause");
	return 0;
}