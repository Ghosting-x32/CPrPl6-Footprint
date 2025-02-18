#include<iostream>
#include<string>
const int Yue = 12;
const int Year = 3;
int main()
{
	using namespace std;
	int ersyxl[Year][Yue];
	string* yf = new string[Yue];
	int xszl[Year][Yue];

	int a = 0;
	while (a < Year)
	{
		for (int i = 0; i < Yue; ++i)
		{
			yf[i] = "月份：";
			cout << i + 1 << yf[i];
			cin >> ersyxl[a][i];
		}
		int j = 1;
		xszl[a][0] = ersyxl[a][0];
		while (j < Yue)
		{
			xszl[a][j] = xszl[a][j - 1] + ersyxl[a][j];
			++j;
		}
		cout << "第" << a + 1 << "年销售总量是：" << xszl[a][j - 1] << endl;
		++a;
	}

	cout << "三年总销量是：" << xszl[0][Yue - 1] + xszl[1][Yue - 1] + xszl[2][Yue - 1];


	delete[] yf;

	cin.get();
	cin.get();
	return 0;
}