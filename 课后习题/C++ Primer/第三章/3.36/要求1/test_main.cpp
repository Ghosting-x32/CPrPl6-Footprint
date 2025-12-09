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
	int arr1[4] = {0, 2};
	int arr2[4] = {};
	string arr3[4] = {};//不是内置类型的数组各个元素做比较，编译器会报错，比如：int 的3不能和string 的"hello"做比较，但是int 的3能和double的3做比较
	//编译器会隐式转换，将int的3转换为double再做比较

	const std::type_info& ti = typeid(arr1);
	cout << ti.name() << endl;

	auto arr1_size = sizeof(arr1) / sizeof(arr1[0]);
	auto arr2_size = sizeof(arr2) / sizeof(arr2[0]);

	if (arr1_size != arr2_size || typeid(arr1) != typeid(arr2))//判断两个变量的类型是否相同---typeid(arr1) != typeid(arr2)
		//typeid(arr1)的返回类型是std::type_info,因为数组的类型是内置类型加维度，所以，其实用typeid(arr1) != typeid(arr2)判断就行，无需判断维度是否相等了
	{
		cout << "数组arr1 和arr2的元素个数（维度）不相等,或者类型不同，所以两个数组不相等！" << endl;
	}
	else
	{
		size_t i = 0;
		for (;i < arr1_size; i++)
		{
			if (arr1[i] != arr2[i])
			{
				cout << "数组arr1和数组arr2的元素个数（维度）相等，类型也相同，但第 " << i +1 << " 个元素不相等，所以两个数组不相等！" << endl;
				cout << "数组arr1的第 " << i + 1 << " 个元素是 " << arr1[i] << "\t数组arr2的第 " << i + 1 << " 个元素是 " << arr2[i] << endl;
				break;
			}
		}
		
		if (i == arr1_size && arr1[i - 1] == arr2[i - 1])
		{
			cout << "数组arr1和数组arr2的元素个数（维度）相等，类型也相同,对应的各个元素也相等，所以两个数组相等！" << endl;
		}



	}


	
	


	system("pause");
	return 0;
}