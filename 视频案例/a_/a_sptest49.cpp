#include <iostream>
#include<string>


int main()
{
	using namespace std;
	//二维数组案例，学生成绩统计
	//1.创建一个二维数组
	int scores[3][3] =
	{
		{100,100,100},
		{90,50,100},
		{60,70,80}
	};
	string names[3] = { "张三","李四","王五" };

	//2.进行成绩统计
	for (int i = 0; i < 3; i++)
	{
		int sum = 0;
		for (int j = 0; j < 3; j++)
		{
			sum += scores[i][j];
		}
		cout << names[i] << "的总成绩是：" << sum << endl;
	}


	system("pause");
	return 0;
}


