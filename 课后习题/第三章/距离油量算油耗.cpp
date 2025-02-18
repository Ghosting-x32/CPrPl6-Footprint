#include <iostream>
int main()
{
	using namespace std;
	const int Ajl = 100;
	double jl, yl;
	cout << "请输入行驶距离：";
	cin >> jl;
	cout << "请输入消耗油量：";
	cin >> yl;
	double yh = Ajl * yl / jl;
	cout << "你的爱车油耗量是：" << yh;
	cin.get();
	cin.get();
	return 0;
}
