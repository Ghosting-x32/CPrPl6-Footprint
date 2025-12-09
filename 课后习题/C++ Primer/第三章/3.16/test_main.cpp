#include<iostream>
#include<vector>
#include<string>



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
	for (auto& c : v1)
	{
		
		cout << c << " ";
	}

	cout << "v1输出结束!" << endl << endl;

	cout << "v2的元素个数: " << v2.size() << endl;
	cout << "v2的各个元素是: ";

	for (auto& c : v2)
	{

		cout << c << " ";
	}

	cout << "v2输出结束!" << endl << endl;

	cout << "v3的元素个数: " << v3.size() << endl;
	cout << "v3的各个元素是: ";

	for (auto& c : v3)
	{

		cout << c << " ";
	}

	cout << "v3输出结束!" << endl << endl;

	cout << "v4的元素个数: " << v4.size() << endl;
	cout << "v4的各个元素是: ";

	for (auto& c : v4)
	{

		cout << c << " ";
	}

	cout << "v4输出结束!" << endl << endl;

	cout << "v5的元素个数: " << v5.size() << endl;
	cout << "v5的各个元素是: ";

	for (auto& c : v5)
	{

		cout << c << " ";
	}

	cout << "v5输出结束!" << endl << endl;

	cout << "v6的元素个数: " << v6.size() << endl;
	cout << "v6的各个元素是: ";

	for (auto& c : v6)
	{

		cout << c << " ";
	}

	cout << "v6输出结束!" << endl << endl;

	cout << "v7的元素个数: " << v7.size() << endl;
	cout << "v7的各个元素是: ";

	for (auto& c : v7)
	{

		cout << c << " ";
	}

	cout << "v7输出结束!" << endl << endl;


	system("pause");
	return 0;
}