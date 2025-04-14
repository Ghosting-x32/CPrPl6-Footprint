#include <iostream>


int main()
{
	using namespace std;
	//敲桌子游戏
	//1.打印1~100的所有数字。
	for (int i = 1; i <= 100; i++)
	{
		//2.找出特殊数字，打印“敲桌子”。
			//个位有7，十位有7，7的倍数，视为特殊数字。

		if (i % 10 == 7 || i / 10 == 7 || i % 7 == 0)
		{
			cout << "敲桌子" << endl;
		}
		else
		{
			cout << i << endl;
		}
	}
	




	

	system("pause");
	return 0;
}


