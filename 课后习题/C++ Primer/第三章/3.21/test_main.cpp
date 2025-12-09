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
	vector<int> v1;
	vector<int> v2(10);
	vector<int> v3(10, 42);
	vector<int> v4{ 10 };
	vector<int> v5{ 10, 42 };
	vector<string> v6{ 10 };
	vector<string> v7{ 10, "hi" };

	cout << "v1的元素个数: " << v1.size() << endl;
	cout << "v1的各个元素是: ";

	for (auto it = v1.cbegin(); it != v1.cend(); it++)
	{
		cout << *it << " ";
	}




	cout << "v1输出结束!" << endl << endl;

	cout << "v2的元素个数: " << v2.size() << endl;
	cout << "v2的各个元素是: ";

	for (auto it = v2.cbegin(); it != v2.cend(); it++)
	{
		cout << *it << " ";
	}

	cout << "v2输出结束!" << endl << endl;

	cout << "v3的元素个数: " << v3.size() << endl;
	cout << "v3的各个元素是: ";

	for (auto it = v3.cbegin(); it != v3.cend(); it++)
	{
		cout << *it << " ";
	}

	cout << "v3输出结束!" << endl << endl;

	cout << "v4的元素个数: " << v4.size() << endl;
	cout << "v4的各个元素是: ";

	for (auto it = v4.cbegin(); it != v4.cend(); it++)
	{
		cout << *it << " ";
	}

	cout << "v4输出结束!" << endl << endl;

	cout << "v5的元素个数: " << v5.size() << endl;
	cout << "v5的各个元素是: ";

	for (auto it = v5.cbegin(); it != v5.cend(); it++)
	{
		cout << *it << " ";
	}

	cout << "v5输出结束!" << endl << endl;

	cout << "v6的元素个数: " << v6.size() << endl;
	cout << "v6的各个元素是: ";

	for (auto it = v6.cbegin(); it != v6.cend(); it++)
	{
		cout << *it << " ";
	}

	cout << "v6输出结束!" << endl << endl;

	cout << "v7的元素个数: " << v7.size() << endl;
	cout << "v7的各个元素是: ";

	for (auto it = v7.cbegin(); it != v7.cend(); it++)
	{
		cout << *it << " ";
	}

	cout << "v7输出结束!" << endl << endl;



	system("pause");
	return 0;
}