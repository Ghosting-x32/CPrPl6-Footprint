#include <iostream>
#include<cmath>
int main()
{
	using namespace std;
	const int Acc = 12;
	const double Acm = 0.0254;
	const double Abq = 2.2;
	double yci, ycn,ban;
	cout << "请输入你以英尺为单位部分的身高数值：___\b\b\b";
	cin >> yci;
	cout << "请输入你以英寸为单位部分的身高数值：___\b\b\b";
	cin >> ycn;
	cout << "请输入你以榜为单位的体重数值：____\b\b\b\b";
	cin >> ban;
	double mi = (yci * Acc + ycn) * Acm;
	double qk = ban / Abq;
	double IBM = qk / pow(mi,2);
	cout << "你的体重指数是：" << IBM << endl;
	cin.get();
	cin.get();
	return 0;
}
