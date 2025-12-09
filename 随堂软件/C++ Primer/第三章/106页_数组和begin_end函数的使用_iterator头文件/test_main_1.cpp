#include<iostream>
#include<vector>
#include<string>
#include<cctype>
#include<iterator>



using std::cin;
using std::cout;
using std::endl;
using std::vector;    
using std::string;
using std::begin;
using std::end;




int main()
{
	int arr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int* p = arr;
	++p;

	int* e = &arr[10];

	for (int* b = arr; b != e; ++b)
	{
		cout << *b << endl;
	}
	
	int* pbeg = begin(arr);//返回指向数组第一个元素的指针
	int* pend = end(arr);//返回指向数组最后一个元素的下一个位置的指针
	for (int* b = pbeg; b != pend; b++)
	{
		cout << *b << endl;
	}




	system("pause");
	return 0;
}