#include<iostream>
#include<string>


#include"HasFriendT.h"


using namespace std;



int main()
{
	
	counts<int>();//����ģ��ĵ���---��ʾ����
	HasFriendT<int>hfi1(10);	
	HasFriendT<int>hfi2(20);	
	HasFriendT<double>hfdb(10.5);
	
	reports<>(hfi1);//����ģ��ĵ���---�Զ������Ƶ�
	reports<HasFriendT<int>>(hfi2);//����ģ��ĵ���---��ʾ����
	reports<>(hfdb);

	cout << "counts<int>() output:\n";
	counts<int>();

	cout << "counts<double>() output:\n";
	counts<double>();


	system("pause");
	return 0;
}