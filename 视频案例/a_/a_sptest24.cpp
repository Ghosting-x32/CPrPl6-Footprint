#include <iostream>

int main()
{
	using namespace std;
//用户输入高考分数，如果分数高于600，则视为考上一本大学，并在屏幕上输出。
	//1.提醒用户输入高考分数
	int score = 0;
	cout << "请输入你的高考分数：";
	cin >> score;
	//2.打印用户输入的分数
	cout << "你输入的高考分数是：" << score << endl;
	//3.告知用户是否考上一本大学
	if (score > 600)
	{
		cout << "恭喜你考上了一本大学！！\a\n";
	}

	
	system("pause");
	return 0;
}


