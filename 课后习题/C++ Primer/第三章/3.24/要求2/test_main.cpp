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
	int a = 0;
	int b = 0;

	cout << "请输入一组整数: " << endl;
	while (cin >> a)
	{
		v1.push_back(a);
	}

	cout << "你输入的一组整数是: " << endl;
	for (auto& c : v1)
	{
		cout << c << " ";

	}
	cout << endl;

	cout << "每对首尾的整数的和分别是: " << endl;//第一个和最后一个的和，第二个和倒数第二个的和......依此类推


	if (v1.size() % 2 == 0)
	{
		for (auto it = v1.begin(); it != (v1.begin() + (v1.end() - v1.begin()) / 2); it++)
		{
			b = (*it) + *(v1.begin() + (v1.end() - it) - 1);

			cout << b << " ";
		}

	}
	else
	{
		for (auto it = v1.begin(); it <= (v1.begin() + (v1.end() - v1.begin()) / 2); it++)
		{
			if (it == (v1.begin() + (v1.end() - v1.begin()) / 2))
			{
				b = *it;
				cout << b << " ";
			}
			else
			{
				b = (*it) + *(v1.begin() + (v1.end() - it) - 1);

				cout << b << " ";

			}
		}
	}
	




	//for (decltype(v1.size()) i = 0; i < v1.size(); i++)
	//{
	//	if (i < (v1.size() - i - 1))
	//	{
	//		b = v1[i] + v1[v1.size() - i - 1];
	//		cout << b << " ";
	//	}
	//	else if (i == (v1.size() - i - 1))
	//	{
	//		b = v1[i];
	//		cout << b << " ";
	//	}
	//	else
	//	{
	//		break;
	//	}

	//}

	cout << endl;







	system("pause");
	return 0;
}