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
	//找到数组arr中的第一个负数
	int arr[] = { 0, 1, 2, 3, 4, 5, 6, -7, -8, 9 };
	
	int* pbeg = begin(arr);//返回指向数组第一个元素的指针
	int* pend = end(arr);//返回指向数组最后一个元素的下一个位置的指针
	int a = 0;

	for (int* b = pbeg; b != pend; b++)
	{
		cout << *b << " ";
		
	}
	cout << endl;

	while (pbeg != pend && *pbeg >= 0)
	{
		++pbeg;
		++a;
	}

	if (pbeg != pend && *pbeg < 0)
	{
		cout << "循环寻找了 " << a << " 次。";
		cout << "找到了arr里面的第一个负数是: " << *pbeg << endl;
	}
	if (pbeg == pend)
	{
		cout << "循环寻找了 " << a << " 次。";
		cout << "arr中没有负数！" << endl;
	}


	system("pause");
	return 0;
}