#include<iostream>

int main()
{
	/*
	*aaa
	*bbb
	*ccc
	/*  ddd  */
	*/
//上面这样的注释会报错，最后一个*/程序运行当做程序代码处理

/*
* 注释对/* */不能嵌套。
* “不能嵌套”几个字会被认为是源码，
* 像剩余程序一样处理
*/
//编译器会报告：
//4 error: stray '\262' in program
//4 error: stray '\273' in program
//（篇幅所限，后续错误信息略。）
//原因是编译器将第一个“*/”看作注释结束，之后的中文文字看作下一条语句，
//从而给出非法字符的错误信息。如果“*/”之后是英文文字，或是使用其他编译器
//进行编译，给出的可能是完全不同的错误信息。而且这些错误信息都很难直接与注
//释错误嵌套挂上钩，程序员需要有一定的经验才能快速定位错误，确定错误原因。



	std::cout << "Enter two numbers:";
	std::cout << std::endl;
	int v1 = 0;
	int v2 = 0;
	std::cin >> v1;
	std::cin >> v2;
	std::cout << "The sum of ";
	std::cout << v1;
	std::cout << " and ";
	std::cout << v2;
	std::cout << " is ";
	std::cout << v1 + v2;
	std::cout << std::endl;



	system("pause");
	return 0;
}