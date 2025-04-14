#include<iostream>
#include<string>


using namespace std;
void test01();

template<typename T>
void MySwap(T& a, T& b)//函数模板的声明和定义必须在一起
{
	T temp = a;
	a = b;
	b = temp;
}

template<typename T>
void MySort(T arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		int Max = i;
		for (int j = i + 1; j < len; j++)
		{
			if (arr[Max] < arr[j])
			{
				Max = j;
			}
		}
		if (Max != i)
		{
			//T temp = arr[Max];
			//arr[Max] = arr[i];
			//arr[i] = temp;
			MySwap(arr[Max], arr[i]);//自动类型推导，嵌套使用函数模板
		}		
	}
}

template<typename T>
void PrintArray(T arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}


int main()
{
	test01();


	system("pause");
	return 0;
}



void test01()
{
	//自动类型推导
	char arr[] = { "asdfghjklqwertyuiopzxcvbnm" };
	int num = sizeof(arr) / sizeof(arr[0]);
	cout << "排序之前的arr: " << endl;
	PrintArray(arr, num);

	MySort(arr, num);	
	PrintArray(arr, num);

	cout << "----------------------" << endl;
	//显示指定类型
	int arr1[] = { 5,9,6,3,7,8,4,1,2,0 };
	int num1 = sizeof(arr1) / sizeof(arr1[0]);
	cout << "排序之前的arr1: " << endl;
	PrintArray<int>(arr1, num1);
	MySort<int>(arr1, num1);
	PrintArray<int>(arr1, num1);

}



