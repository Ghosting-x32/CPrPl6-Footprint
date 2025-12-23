#include<iostream>
#include<vector>
#include<string>
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




double myADD(double val1, double val2);


int main()
{

	/*
	形参和定义在函数体内部的变量统称为局部变量，它们对函数而言是局部的，
仅在函数的作用域内可见。函数体内的局部变量又分为普通局部变量和静态局部变
量，对于形参和普通局部变量来说，当函数的控制路径经过变量定义语句时创建该
对象，当到达定义所在的块末尾时销毁它。我们把只存在于块执行期间的对象称为
自动对象。这几个概念的区别是：
 形参是一种自动对象，函数开始时为形参申请内存空间，我们用调用函数时
提供的实参初始化形参对应的自动对象。
 普通变量对应的自动对象也容易理解，我们在定义该变量的语句处创建自动
对象，如果定义语句提供了初始值，则用该值初始化；否则，执行默认初始
化。当该变量所在的块结束后，变量失效。
 局部静态变量比较特殊，它的生命周期贯穿函数调用及之后的时间。局部静
态变量对应的对象称为局部静态对象，它的生命周期从定义语句处开始，直
到程序结束才终止。	
	
	*/
	
	double num1 = 0, num2 = 0, num3 = 0;
	cout << "请输入两个数：";
	while (cin >> num1 >> num2)
	{
		num3 = myADD(num1, num2);
		cout << num1 << "与" << num2 << "的求和结果是："
			<< num3 << endl;
	}



	system("pause");
	return 0;
}



double myADD(double val1, double val2) // val1 和val2 是形参
{
	double result = val1 + val2; // result 是普通局部变量
	static unsigned iCnt = 0; // iCnt 是静态局部变量
	++iCnt;
	cout << "该函数已经累计执行了" << iCnt << "次" << endl;
	return result;
}