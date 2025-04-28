#include<iostream>
#include<string>


#include"HasFriend.h"


using namespace std;



int main()
{
	cout << "No objects declared: ";
	counts();
	HasFriend<int>hfi1(10);
	cout << "After hfi1 declared: ";
	counts();
	HasFriend<int>hfi2(20);
	cout << "After hfi2 declared: ";
	counts();
	HasFriend<double>hfdb(10.5);
	cout << "After hfdb declared: ";
	counts();
	reports(hfi1);
	reports(hfi2);
	reports(hfdb);

	system("pause");
	return 0;
}