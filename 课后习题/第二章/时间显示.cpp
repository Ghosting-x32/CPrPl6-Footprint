#include<iostream>
void 时间链接(int,int);
int main()
{
	时间链接(1, 2);
	return 0;
}

void 时间链接(int n,int m)
{
	using namespace std;
	cout << "Enter the number of hours: ";
	cin >> n;
	cout << "Enter the number of minutes: ";
	cin >> m;
	cout << "Time: " << n << ":" << m;
	cin.get();
	cin.get();
}
