#include<iostream>
using namespace std;
struct CandyBar
{
	const char* ppmc;
	double zl;
	int rl;
};

void f1(CandyBar& aq, const char* pn = "Millennium", const double x = 2.85, const int y = 350);
void show(const CandyBar& ar);


int main()
{
	CandyBar csjg;
	const char* ps = "hahahahhah";
	double cszl = 3.69;
	int csrl = 693;
	f1(csjg);
	show(csjg);
	f1(csjg, ps, cszl, csrl);
	show(csjg);





	system("pause");
	return 0;
}

void show(const CandyBar& ar)
{
	cout << "品牌名称：" << ar.ppmc << endl;
	cout << "重量：" << ar.zl<< endl;
	cout << "热量：" << ar.rl << endl;
}

void f1(CandyBar& aq, const char* pn, const double x, const int y)
{
	aq.ppmc = pn;
	aq.zl = x;
	aq.rl = y;
}