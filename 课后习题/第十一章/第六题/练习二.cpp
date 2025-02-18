#include<iostream>
#include"stonewt.h"
const int szcd = 6;


int main()
{
	Stonewt stsz[szcd] = { 625.2, 36.21, 652.6};
	Stonewt stwt11(11, 0);
	for (int i = 3; i < szcd; i++)
	{
		double lspo;
		std::cout << "请输入第 " << i + 1 << "个类数组成员：";
		std::cin >> lspo;
		stsz[i] = lspo;
	}
	Stonewt stzx = stsz[0];
	for (int i = 1; i < szcd; i++)
	{
		if (stzx < stsz[i])
			stzx = stzx;
		else
			stzx = stsz[i];
	}
	std::cout << "最小的元素是：" << std::endl;
	stzx.show_stn();

	Stonewt stzd = stsz[0];
	for (int i = 1; i < szcd; i++)
	{
		if (stzd > stsz[i])
			stzd = stzd;
		else
			stzd = stsz[i];
	}
	std::cout << "最大的元素是：" << std::endl;
	stzd.show_stn();

	int dy11 = 0;
	for (int i = 0; i < szcd; i++)
	{
		if (stsz[i] >= stwt11)
			dy11++;
	}
	std::cout << "大于或等于11英石的元素数量是：" << dy11 << std::endl;





	system("pause");
	return 0;
}

