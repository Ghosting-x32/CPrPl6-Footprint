#include<iostream>
#include<string>
#include<cmath>
#include<iomanip>


using namespace std;

int main()
{
	cout << fixed << right;//控制符使用定点表示法和右对齐
	cout << setw(6) << "N" << setw(14) << "square root" << setw(15) << "fourth root\n";
	//头文件<iomanip>提供的控制符，设置字段宽度

	double root;
	for (int n = 10; n <= 100; n += 10)
	{
		root = sqrt(double(n));
		cout << setw(6) << setfill('.') << n
			<< setfill(' ') << setw(12) << setprecision(3) << root
			//头文件<iomanip>提供的控制符，设置填充字符，设置字段宽度，设置精度
			<< setw(14) << setprecision(4) << sqrt(root) << endl;

	}





	system("pause");
	return 0;
}