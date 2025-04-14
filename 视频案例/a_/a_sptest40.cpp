#include <iostream>


int main()
{
	using namespace std;
	//continue对0~100内数字进行输出（只输出奇数）
	for (int i = 0; i <= 100; i++)
	{
		if (i % 2 == 0)
		{
			continue;
		}
		cout << i << endl;
	}


	system("pause");
	return 0;
}


