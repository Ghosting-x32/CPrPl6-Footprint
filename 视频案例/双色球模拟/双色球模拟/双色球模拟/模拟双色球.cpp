#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<random>

using namespace std;

void tex1(int val)
{
	cout << val << " ";
}

int main()
{
	random_device rd;
	mt19937 gen(rd());
	//uniform_int_distribution<> dis(1, 100);

	vector<int>hongse;
	vector<int>lanse;

	for (int i = 1; i < 34; i++)//准备红球
	{
		hongse.push_back(i);
	}

	for_each(hongse.begin(), hongse.end(), tex1);
	cout << endl;
	cout << "红球准备就绪！" << endl;
	system("pause");

	for (int i = 1; i < 17; i++)//准备篮球
	{
		lanse.push_back(i);
	}

	for_each(lanse.begin(), lanse.end(), tex1);
	cout << endl;
	cout << "蓝球准备就绪！" << endl;
	cout << "--------------------------------------------------------------------------------------------------" << endl;
	system("pause");
	
	cout << "预洗牌5次准备！" << endl;
	system("pause");
	for (int i = 0; i < 5; i++)//预洗牌5次
	{
		shuffle(hongse.begin(), hongse.end(), gen);
		cout << hongse.size() << endl;
		for_each(hongse.begin(), hongse.end(), tex1);
		cout << endl;

		shuffle(lanse.begin(), lanse.end(), gen);
		cout << lanse.size() << endl;
		for_each(lanse.begin(), lanse.end(), tex1);
		cout << endl;
		cout << "--------------------------------------------------------------------------------------------------" << endl;
	}

	cout << "洗牌成功！" << endl;
	system("pause");
	system("cls");


	cout << "\n\n***抽红球***\n" << endl;
	system("pause");
	//抽红色球
	int i = 1;
	vector<int>hongsejg;
	hongsejg.resize(6);
	for (vector<int>::iterator it = hongse.begin(); it != hongse.end() && i < 7; it++ , i++)
	{
		for (int i = 0; i < 3; i++)
		{
			shuffle(hongse.begin(), hongse.end(), gen);
		}
		
		cout << "现在共有 " << hongse.size() << " 个红球" << endl;
		cout << "第 " << i << " 个抽出的红球：" << hongse[33 - i] << endl;
		hongsejg[i - 1] = hongse[33 - i];

		hongse.pop_back();

		cout << "剩余红球如下：" << endl;
		for_each(hongse.begin(), hongse.end(), tex1);
		cout << endl;

		cout << "-------------------------------------" << endl;
	}
	cout << "现在共有 " << hongse.size() << " 个红球" << endl;
	cout << "-------------------------------------" << endl;

	system("pause");
	cout << "\n\n***抽蓝球***\n" << endl;
	system("pause");
	//抽蓝色球
	int lansejg = 0;
	for (int i = 0; i < 3; i++)//洗牌3次
	{
		shuffle(lanse.begin(), lanse.end(), gen);
	}

	cout << "现在共有 " << lanse.size() << " 个篮球" << endl;
	cout << "第 1 个抽出的篮球：" << lanse[15] << endl;
	lansejg = lanse[15];
	lanse.pop_back();
	cout << "剩余的篮球如下：" << endl;
	for_each(lanse.begin(), lanse.end(), tex1);
	cout << endl;
	cout << "-------------------------------------" << endl;
	cout << "现在共有 " << lanse.size() << " 个蓝球" << endl;
	cout << "-------------------------------------" << endl;
	system("pause");

	//最终结果展示
	cout << "\n\n\n***红色球最终结果***" << endl;
	cout << "=================================================" << endl;
	for_each(hongsejg.begin(), hongsejg.end(), tex1);
	cout << endl;
	cout << "=================================================" << endl;

	

	cout << "\n\n\n***蓝色球最终结果***" << endl;
	cout << "=================================================" << endl;
	cout << lansejg << endl;
	cout << "=================================================" << endl;










	system("pause");
	return 0;
}