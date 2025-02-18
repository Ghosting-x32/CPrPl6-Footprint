#include<iostream>
#include<array>
const int ArSize = 10;
int main()
{
	using namespace std;
	array <double, ArSize> donation;
	cout << "第1个数是: ";
	int i = 0;
	while (i < ArSize && cin >> donation[i])
	{
		if (++i < ArSize)
			cout << "第" << i + 1 << "个数是: ";
	}
	double total = 0.0;
	for (int j = 0; j < i; j++)
		total += donation[j];
	if (i == 0)
		cout << "没有输入有效的数字！";
	else
	{
		double pj = total / i;
		cout << "输入数字的平均数是：" << pj << endl;
		int k = 0;
		int cd = 0;
		while (k < i)
		{
			if (donation[k] > pj)
				++cd;
			++k;
		}
		cout << "输入数字中有" << cd << "个大于平均值。";

	}


	cin.get();
	cin.get();
	return 0;
}
