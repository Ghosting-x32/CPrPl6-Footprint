#include<iostream>
#include<string>
const int Yue = 12;

int main()
{
	using namespace std;
	string* yf = new string [Yue];
	int* xsl = new int[Yue];
	int* xszl = new int[Yue];
	for (int i = 0; i < Yue; ++i)
	{
		yf[i] = "月份：";
		cout << i + 1 <<  yf[i];
		cin >> xsl[i];
	}
	int j = 1;
	xszl[0] = xsl[0];
	while (j < Yue)
	{
		 xszl[j] = xszl[j - 1] + xsl[j];
		++j;
	}
	cout << "年销售总量是：" << xszl[j - 1];
	delete[] yf;
	delete[] xsl;
	delete[] xszl;

	cin.get();
	cin.get();
	return 0;
}