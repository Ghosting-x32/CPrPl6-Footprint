#include<iostream>
#include"Useless.h"

using namespace std;



int main()
{
	{
		Useless one(10, 'x');
		Useless two = one;
		Useless three(20, 'o');
		Useless four(one + three);
		//程序输出中没有走移动构造函数和复制构造函数是因为：返回值优化（RVO）
		//temp 直接在 four 的内存位置构造（RVO）
		//1.RVO 是默认启用且不可禁用的核心优化
		//2.在 C++17 模式下，RVO 是语言标准强制要求的行为
		//3.这是符合标准的积极优化，不应强制避免

		//与用g++进行编译的效果一样



		//程序输出：
	    /*int, char constructor called : number of objects : 1
		number of elements : 10 Data address : 0000028E42B358E0
		copy const called; number of objects : 2
		number of elements : 10 Data address : 0000028E42B35AC0
		int, char constructor called : number of objects : 3
		number of elements : 20 Data address : 0000028E42B35D40
		Entering operator+()
		int constructor called; number of objects : 4
		number of elements : 30 Data address : 0000028E42B30B40
		temp object :
	    Leaving operator+()----------------------------------------------走完Useless operator+(const Useless& f)const;函数，后直接走下面*1*的代码，没有走移动构造函数
		object one : xxxxxxxxxx
		object two : xxxxxxxxxx
		object three : oooooooooooooooooooo
		object four : xxxxxxxxxxoooooooooooooooooooo
		destructor called : objects left : 3
		deleted object :
	    number of elements : 30 Data address : 0000028E42B30B40
		destructor called : objects left : 2
		deleted object :
	    number of elements : 20 Data address : 0000028E42B35D40
		destructor called : objects left : 1
		deleted object :
	    number of elements : 10 Data address : 0000028E42B35AC0
		destructor called : objects left : 0
		deleted object :
	    number of elements : 10 Data address : 0000028E42B358E0
		请按任意键继续. . .*/

		//*1*
		cout << "object one: ";
		one.ShowData();
		cout << "object two: ";
		two.ShowData();
		cout << "object three: ";
		three.ShowData();
		cout << "object four: ";
		four.ShowData();
	
	
	}//代码块便于显示析构函数

	system("pause");
	return 0;
}