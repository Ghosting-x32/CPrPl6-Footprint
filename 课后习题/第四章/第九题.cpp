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
	CandyBar* pn = new CandyBar[3];

	pn[0] =
	{
		"Mocha Munch",
		2.3,
		350
	};
	pn[1] =
	{
		"Gocha Gunch",
		3.2,
		650
	};
	pn[2] =
	{
		"Locha Lunch",
		6.4,
		987
	};

	cout << "三个结构内容如下:\n";
	cout << "snack品牌：" << pn->ppa << endl;
	cout << "snack重量：" << pn->zl << endl;
	cout << "snack卡路里：" << pn->kll << endl << endl;

	cout << "snack2品牌：" << (pn + 1)->ppa << endl;
	cout << "snack2重量：" << (pn + 1)->zl << endl;
	cout << "snack2卡路里：" << (pn + 1)->kll << endl << endl;

	cout << "snack3品牌：" << (pn + 2)->ppa << endl;
	cout << "snack3重量：" << (pn + 2)->zl << endl;
	cout << "snack3卡路里：" << (pn + 2)->kll << endl;
	delete[] pn;

	cin.get();
	cin.get();
	return 0;
}
