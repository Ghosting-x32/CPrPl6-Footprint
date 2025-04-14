#include <iostream>


int main()
{
	using namespace std;
	//利用嵌套循环实现星图
	for (int i = 0; i < 10; i++)//外层循环为i
	{
		for (int j = 0; j < 10; j++)//内层循环为j
		{
			cout << "* ";
		}
		cout << endl;
	}
	




	

	system("pause");
	return 0;
}


