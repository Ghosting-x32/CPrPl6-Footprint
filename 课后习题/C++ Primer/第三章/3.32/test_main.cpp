#include<iostream>
#include<vector>
#include<string>
#include<cctype>



using std::cin;
using std::cout;
using std::endl;
using std::vector;    
using std::string;




int main()
{

	int arr[10] = {};

	for (size_t i = 0; i < 10; i++)
	{
		arr[i] = i;
	}

	cout << "arr的各个元素分别为: " << endl;
	for (auto& c : arr)
	{
		cout << c << " ";
	}
	cout << endl;


	int arr1[10] = {};
	cout << "arr1的各个元素分别为: " << endl;
	for (auto& c : arr1)
	{
		cout << c << " ";
	}
	cout << endl;

	for (size_t i = 0; i < 10; i++)
	{
		arr1[i] = arr[i];
	}



	cout << "将arr拷贝给arr1后，arr1的各个元素分别为: " << endl;

	for (auto& c : arr1)
	{
		cout << c << " ";
	}
	cout << endl;


	vector<int> v1(10);
	for (decltype(v1.size()) i = 0; i < v1.size(); i++)
	{
		v1[i] = i;
	}

	cout << "v1的各个元素分别为: " << endl;
	for (auto& c : v1)
	{
		cout << c << " ";
	}
	cout << endl;



	vector<int> v2(10);//直接使用复制构造函数更好：vector<int> v2(v1);
	cout << "v2的各个元素分别为: " << endl;
	for (auto& c : v2)
	{
		cout << c << " ";
	}
	cout << endl;

	v2 = v1;

	cout << "将v1拷贝给v2后，v2的各个元素分别为: " << endl;
	for (auto& c : v2)
	{
		cout << c << " ";
	}
	cout << endl;



	system("pause");
	return 0;
}