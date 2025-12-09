#include<iostream>
#include<vector>
#include<string>
#include<cctype>
#include<iterator>
#include<cstddef>
#include<typeinfo>




using std::cin;
using std::cout;
using std::endl;
using std::vector;    
using std::string;
using std::begin;
using std::end;
using std::size_t;
using std::ptrdiff_t;




int main()
{
	vector<int> v1(10);
	vector<double> v2(10);
	vector<string> v3(10);
	vector<int> v4(9);
	v4.push_back(2);



	if (typeid(v1) != typeid(v4))//其实这一步的判断都没有必要，因为类型不同的话编译器会报错
	{
		cout << "vector对象v1和vector对象v2的类型不同，所以他们不相等!" << endl;
	}
	else
	{
		if (v1 == v4)//两个不同类型的vector对象做比较编译器会报错，比如：v1 == v2
		{
			cout << "vector对象v1和vector对象v2的类型相同，元素个数也相同，对应的每个元素也相同，所以他们相等!" << endl;
		}
		else
		{
			cout << "vector对象v1和vector对象v2的类型相同，但是元素个数不相同或者对应的某个元素不相同，所以他们不相等!" << endl;
		}

	}





	
	


	system("pause");
	return 0;
}