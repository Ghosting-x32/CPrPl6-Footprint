#include<iostream>
#include<vector>
#include<string>
#include<iterator>
#include<cstddef>
#include<cctype>
#include<stdexcept>





using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::begin;
using std::end;
using std::size_t;
using std::isupper;
using std::runtime_error;





int main()
{
	/*
	在本题中，我们设定当检测到除数为0 时抛出一个runtime_error 异常，因
为没有catch 语句，所以系统只报告异常而并不处理它。在我们的编译环境中，系
统给出的报错信息是：
terminate called after throwing an instance of 'std::runtime_error'
what(): 除数不能为0
This application has requested the Runtime to terminate it in an unusual
way. Please contact the application’s support team for more information.
	
	*/

		int val1 = 0, val2 = 0;

		cout << "请输入两个整数:" << endl;
		cin >> val1 >> val2;
		if (val2 == 0)
		{
			throw runtime_error("除数不能为0");
		}
		cout << val1 << " ÷ " << val2 << " = " << val1 / val2 << endl;






	system("pause");
	return 0;
}