#include <iostream>


int main()
{
	using namespace std;
	//冒泡排序实现数组内容升序排列
	//1.创建一个数组
	int arr[9] = { 4,2,8,0,5,7,1,3,9 };
	cout << "排序前的数组内容是：" << endl;
	for (int i = 0; i < 9; i++)
	{

		cout << arr[i] << " ";
	}
	cout << endl;
	//2.进行冒泡排序
	for (int i = 0; i < 9 - 1; i++)
	{
		for (int j = 0; j < 9 - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}

	cout << "排序后的数组内容是：" << endl;
	for (int i = 0; i < 9; i++)
	{

		cout << arr[i] << " ";
	}
	cout << endl;



	system("pause");
	return 0;
}


