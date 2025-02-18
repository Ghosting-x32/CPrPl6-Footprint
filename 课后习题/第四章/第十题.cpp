#include <iostream>
#include<array>
#include<cstring>
int main()
{
	using namespace std;
	array<double, 3> pn;
	cout << "请输入第一次成绩: ";
	cin >> pn[0];
	cout << "请输入第二次成绩: ";
	cin >> pn[1];
	cout << "请输入第三次成绩: ";
	cin >> pn[2];

	int x = pn.size();
	cout << "你的跑步次数是：" << x << endl;
	double pj = (pn[0] + pn[1] + pn[2]) / x;
	cout << "你的平均成绩是：" << pj;
	cin.get();
	cin.get();
	return 0;
}
