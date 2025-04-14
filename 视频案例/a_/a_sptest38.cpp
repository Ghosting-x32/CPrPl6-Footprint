#include <iostream>


int main()
{
	using namespace std;
	//嵌套循环实现9x9乘法口诀表
	for (int i = 1; i <= 9; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			cout << j << " X " << i << " = " << j * i << "  ";
		}
		cout << endl << endl;
	}



	system("pause");
	return 0;
}


