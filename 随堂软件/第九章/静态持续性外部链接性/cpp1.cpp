#include<iostream>
#include"biaotou.h"
double warming = 0.3;
using namespace std;
int main()
{
	cout << "Global warming is " << warming << " degrees.\n";
	update(0.1);
	cout << "Global warming is " << warming << " degrees.\n";
	local();
	cout << "Global warming is " << warming << " degrees.\n";



	system("pause");
	return 0;
}