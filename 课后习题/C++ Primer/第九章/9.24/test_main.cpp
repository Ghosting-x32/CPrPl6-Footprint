#include<iostream>
#include<vector>
#include<string>
#include<iterator>
#include<cstddef>
#include<list>
#include<deque>




using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::vector;
using std::string;
using std::begin;
using std::end;
using std::size_t;
using std::list;
using std::deque;







int main()
{
	
	vector<int> v1;
	vector<int> v2(10, 20);


	int a1 = 0, a2 = 0, a3 = 0, a4 = 0;

	a1 = v2.at(0);
	a2 = v2[0];
	a3 = v2.front();
	a4 = *(v2.begin());

	cout << a1 << " " << a2 << " " << a3 << " " << a4 << endl;



	/*
	
	下面的程序会异常终止。因为vector 为空，此时用at 访问容器的第一个元素
会抛出一个out_of_range 异常，而此程序未捕获异常，因此程序会因异常退出。
正确的编程方式是，捕获可能的out_of_range 异常，进行相应的处理。
但对于后三种获取容器首元素的方法，当容器为空时，不会抛出out_of_range
异常，而是导致程序直接退出（注释掉前几条语句即可看到后面语句的执行效果）。
因此，正确的编程方式是，在采用这几种获取容器的方法时，检查下标的合法性（对
front 和begin 只需检查容器是否为空），确定没有问题后再获取元素。当然这种
方法对at 也适用。
	
	*/

	//a1 = v1.at(0);
	//a2 = v1[0];
	//a3 = v1.front();
	//a4 = *(v1.begin());

	cout << a1 << " " << a2 << " " << a3 << " " << a4 << endl;




	system("pause");
	return 0;
}








