#include<iostream>
#include<vector>
#include<string>
#include<cctype>
#include<iterator>
#include<cstddef>
#include<typeinfo>
#include<cstring>    
#include<climits>
#include<limits>




using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::begin;
using std::end;
using std::size_t;
using std::ptrdiff_t;
using std::strlen;
using std::numeric_limits;




int main()
{
	/*
	* 本题从程序运行结果来说，使用前置版本或后置版本是一样的，这是因为递增
递减运算符与真正使用这两个变量的语句位于不同的表达式中，所以不会有什么影响。
使用后置版本重写的程序是：
vector<int>::size_type cnt = ivec.size();
// 将从size 到1 的值赋给ivec 的元素。
for(vector<int>::size_type ix = 0;ix != ivec.size(); ix++, cnt--)
ivec[ix] = cnt;
根据4.5 节的介绍我们知道，除非必须，否则不用递增（递减）运算符的后置版
本。前置版本的递增运算符避免了不必要的工作，它把值加1 后直接返回改变了的
运算对象。与之相比，后置版本需要将原始值存储下来以便于返回这个未修改的内
容。如果我们不需要修改之前的值，那么后置版本的操作就是一种浪费。
就本题而言，使用前置版本是更好的选择。
	
	*/
	vector<int> ivec(10, 0);
	vector<int>::size_type cnt = ivec.size();
	for (auto& c : ivec)
	{
		cout << c << " ";
	}
	cout << endl;

	for (vector<int>::size_type ix = 0; ix != ivec.size(); ix++, cnt--)
	{
		ivec[ix] = cnt;
	}

	for (auto& c : ivec)
	{
		cout << c << " ";
	}
	cout << endl;





	system("pause");
	return 0;
}