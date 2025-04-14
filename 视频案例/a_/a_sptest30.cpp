#include <iostream>

int main()
{
	using namespace std;
	//给电影打评分
	//10~9   经典电影
	//8~7   感觉非常好电影
	//6~5   感觉一般电影
	//5分以下   烂片

	//1.要求用户输入想打的评分
	int score = 0;
	cout << "请输入你的评分：";
	cin >> score;
	//2.显示用户所打的评分
	cout << "你所打的评分是：" << score << endl;
	//3.判断
	switch (score)
	{
	case 10:
		cout << "你感觉这是一个经典电影！\n";
		break;
	case 9:
		cout << "你感觉这是一个经典电影！\n";
		break;
	case 8:
		cout << "你感觉这是一个非常好的电影！\n";
		break;
	case 7:
		cout << "你感觉这是一个非常好的电影！\n";
		break;
	case 6:
		cout << "你感觉这是一个很一般的电影！\n";
		break;
	case 5:
		cout << "你感觉这是一个很一般的电影！\n";
		break;
	default:
		cout << "你感觉这是一个烂片！\n";
		break;
	}



	system("pause");
	return 0;
}


