#include<iostream>
#include<vector>
#include<string>
#include<cctype>



using std::cin;
using std::cout;
using std::endl;
using std::vector;    
using std::string;




int main()
{
	//int arr1[10];
	int arr[10] = {};

	for (size_t i = 0; i < 10; i++)
	{
		arr[i] = i;
	}

	for (auto& c : arr)
	{
		cout << c << " ";
	}
	cout << endl;

	//for (auto& c : arr1)
	//{
	//	cout << c << " ";
	//}
	//cout << endl;


	system("pause");
	return 0;
}