#include<iostream>
#include<vector>
#include<string>
#include<cctype>
#include<iterator>
#include<cstddef>



using std::cin;
using std::cout;
using std::endl;
using std::vector;    
using std::string;
using std::begin;
using std::end;
using std::size_t;
using std::ptrdiff_t;




int main()
{
	int arr[3] = { 4, 5, 6 };
	cout << "arr原始数据是: " << endl;
	for (auto& c : arr)
	{
		cout << c << " ";
	}

	for (int* p1 = begin(arr); p1 != end(arr); p1++)
	{
		*p1 = 0;
	}



	//for (int* p = &arr[0]; p != &arr[2]; p++)
	//{
	//	*p = 0;
	//}
	
	cout << endl;


	cout << "更改后arr的数据变为: " << endl;
	for (auto& c : arr)
	{
		cout << c << " ";
	}
	cout << endl;


	system("pause");
	return 0;
}