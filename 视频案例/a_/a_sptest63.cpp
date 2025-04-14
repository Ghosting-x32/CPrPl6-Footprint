#include<iostream>
void bubbleSort(int* arr, int len);
void printArray(int* arr, int len);
using namespace std;


int main()
{
	

	//使用指针，数组，函数，冒泡排序算法对一个数组进行升序排序
	//1.创建一个数组
	int arr[10] = { 4,3,6,9,1,2,10,8,7,5 };

	int len = sizeof(arr) / sizeof(arr[0]);
	cout << "原始数组的内容是：" << endl;
	printArray(arr, len);
	//2.创建一个函数实现冒泡排序算法
	bubbleSort(arr, len);
	//3.创建一个打印函数，对数组内容进行打印
	cout << "排序后的数组内容是：" << endl;
	printArray(arr, len);

	system("pause");
	return 0;
}

void bubbleSort(int* arr, int len)
{
	for (int i = 0; i < len - 1; i++)
	{
		for (int j = 0; j < len - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

void printArray(int* arr, int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}