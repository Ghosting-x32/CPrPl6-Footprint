#include<iostream>
#include<vector>
#include<string>
#include<iterator>
#include<cstddef>
#include<cctype>
#include<initializer_list>
#include<cstdlib>//return EXIT_SUCCESS;预处理变量不需要std::(using namdespace std;)







using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::begin;
using std::end;
using std::size_t;
using std::isupper;
using std::tolower;
using std::initializer_list;






int function1(int val1, int val2);
int fc_add(int val1, int val2);
int fc_sub(int val1, int val2);
int fc_mul(int val1, int val2);
int fc_div(int val1, int val2);



int main()
{
	vector<decltype(function1)*> v1;

	v1.push_back(fc_add);

	int (*p_fc_sub)(int val1, int val2) = fc_sub;
	v1.push_back(p_fc_sub);

	v1.push_back(fc_mul);
	v1.push_back(fc_div);



	int (*p_function1)(int val1, int val2) = function1;

	cout << p_function1(3, 8) << endl;
	cout << (*p_function1)(3, 8) << endl;



	cout << v1[0](3, 8) << endl;
	cout << (*v1[1])(3, 8) << endl;
	cout << v1[2](3, 8) << endl;
	cout << v1[3](3, 8) << endl;


	

	system("pause");
	return 0;
}


int function1(int val1, int val2)
{
	if (val1 >= val2)
	{
		return val1;
	}
	else
	{
		return val2;
	}

}


int fc_add(int val1, int val2)
{

	return val1 + val2;
}


int fc_sub(int val1, int val2)
{
	if (val1 >= val2)
	{
		return val1 - val2;
	}
	else
	{
		return val2 - val1;
	}
}


int fc_mul(int val1, int val2)
{
	return val1 * val2;

}


int fc_div(int val1, int val2)
{
	if (val1 >= val2)
	{
		return val1 / val2;
	}
	else
	{
		return val2 / val1;
	}

}






