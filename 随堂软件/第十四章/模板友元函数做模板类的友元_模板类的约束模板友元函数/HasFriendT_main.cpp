#include<iostream>
#include<string>


#include"HasFriendT.h"


using namespace std;



int main()
{
	
	counts<int>();//函数模板的调用---显示类型
	HasFriendT<int>hfi1(10);	
	HasFriendT<int>hfi2(20);	
	HasFriendT<double>hfdb(10.5);
	
	reports<>(hfi1);//函数模板的调用---自动类型推导
	reports<HasFriendT<int>>(hfi2);//函数模板的调用---显示类型
	reports<>(hfdb);

	cout << "counts<int>() output:\n";
	counts<int>();

	cout << "counts<double>() output:\n";
	counts<double>();


	system("pause");
	return 0;
}