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
	vector<int> text;
	for (decltype(text.size()) i = 0; i < 10; i++)
	{
		text.push_back(i + 1);
	}

	text[9] = 100;


	cout << "text的元素个数是: " << text.size() << endl;
	cout << "text的各个元素分别是: " << endl;

	for (auto& c : text)
	{
		cout << c << " ";
	}
	cout << endl;

	int sought = 0;
	int a = 0;
	cout << "请输入你要查找的数: " << endl;
	cin >> sought;

	auto beg = text.begin(), end = text.end();
	auto mid = text.begin() + (end - beg) / 2;

	while (mid != end && mid != beg && *mid != sought)//mid != end && mid != beg,确保sought超过text元素取值范围能正常查找而不报错
	{
		if (sought < *mid)
		{
			end = mid;
		}
		else
		{
			beg = mid + 1;
		}
		mid = beg + (end - beg) / 2;
		a++;
	}


	if (*mid == sought)
	{
		cout << "找到了你查询的数" << sought << " !在text里面是: " << *mid << " !" << endl;
		cout << "二分法循环 " << a << " 次找到！！" << endl;
	}
	else
	{
		cout << "text里面没有你要找的数！！" << endl;
		cout << "二分法循环 " << a << " 次没找到！！" << endl;
	}








	system("pause");
	return 0;
}