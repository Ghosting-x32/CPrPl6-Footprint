#include <iostream>
#include<string>
using namespace std;
struct CandyBar
{
	string ppa;
	double zl;
	int kll;
};
int main()
{
	CandyBar snack =
	{
		"Mocha Munch",
		2.3,
		350
	};
	cout << "snack数据如下:\n";
	cout << "品牌：" << snack.ppa << endl;
	cout << "重量：" << snack.zl << endl;
	cout << "卡路里：" << snack.kll << endl;
	cin.get();
	cin.get();
	return 0;
}
