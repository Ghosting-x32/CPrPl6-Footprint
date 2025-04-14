#include <iostream>


int main()
{
	using namespace std;
	//五只小猪称体重，找出最重小猪的重量
	//1.创建五只小猪重量的数组。
	int arr[5] = { 300 , 350 ,500, 400 ,250 };
	//2.找到最大的重量。
	int max = 0;
	for (int i = 0; i < 5; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}

	}
	cout << "最重的小猪的体重是：" << max << endl;

	system("pause");
	return 0;
}


