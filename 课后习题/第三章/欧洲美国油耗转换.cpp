#include <iostream>
int main()
{
	using namespace std;
	const double Agy = 62.14;
	const double Ajs = 3.785;
	double oyh, myh;
	cout << "请输入你的爱车欧洲版油耗量：";
	cin >> oyh;
	myh = Agy * Ajs / oyh;
	cout << "你的爱车美国版油耗量是：" << myh;
	cin.get();
	cin.get();
	return 0;
}
