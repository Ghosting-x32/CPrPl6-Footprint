#include <iostream>


int main()
{
	using namespace std;
	//实现数组内容逆置
	//1.创建一个数组
	int arr[] = { 1,2,3,4,5,6 }; 
	cout << "逆置前的数组内容是："<< endl;
	for (int i = 0; i < 6; i++)
	{
		cout << arr[i];
	}
	cout << endl;
	
	//2.实现数组逆置
	int start = 0;
	int end = sizeof(arr) / sizeof(arr[0]) - 1;
	int temp = 0;
	while (start < end)
	{
		temp = arr[start];
		arr[start] = arr[end];
		arr[end] = temp;
		start++;
		end--;
	}



	cout << "逆置后的数组内容是：" << endl;
	for (int i = 0; i < 6; i++)
	{
		cout << arr[i];
	}
	cout << endl;

	system("pause");
	return 0;
}


