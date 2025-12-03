#include<iostream>




int reused = 42;

int main()
{
	int unique = 0;
	std::cout << reused << " " << unique << std::endl;
	int reused = 0;
	std::cout << reused << " " << unique << std::endl;
	std::cout << ::reused << " " << unique << std::endl;//用作用域运算符::访问全局的标识符(变量)





	system("pause");
	return 0;
}