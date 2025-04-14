#include <iostream>


int main()
{
	using namespace std;
	//1.打印所有的三位数
	int num = 100;
	do
	{
		//2.找出水仙花数
		int a = 0;//num的个位数
		int b = 0;//num的十位数
		int c = 0;//num的百位数
		a = num % 10;
		b = num / 10 % 10;
		c = num / 100;

		if (a * a *a + b * b * b + c * c * c == num)
		{
			cout << num << endl;
		}
		num++;
	} while (num < 1000);






	

	system("pause");
	return 0;
}


