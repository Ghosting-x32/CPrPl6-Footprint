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
	show2(hfi1, hfi2);//����ģ��ĵ���---�Զ������Ƶ�
	cout << "hfi1, hfdb: ";
	show2<>(hfi1, hfdb);//����ģ��ĵ���---�Զ������Ƶ�
	cout << "hfi2, hfdb: ";
	show2<ManyFriend<int>, ManyFriend<double>>(hfi2, hfdb);//����ģ��ĵ���---��ʾ����




	system("pause");
	return 0;
}