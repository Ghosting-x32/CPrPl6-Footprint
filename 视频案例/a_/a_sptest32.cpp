#include <iostream>
#include<ctime>

int main()
{
	using namespace std;
	//1.系统随机生成一个随机数
	srand((unsigned int)time(NULL));
	int num1 = rand() % 100 + 1;
	//2.用户进行猜测
	int num2 = 0;
	cout << "请输入你猜测的数字：";
	cin >> num2;
	
	
	
	//3.判断
		//猜对了，恭喜猜对了 
		//猜错了，提示猜测数字过大或者过小
	while (1)
	{	
		if (num1 > num2)
		{
			cout << "你的猜测过小!" << endl;
		}
		else if (num1 < num2)
		{
			cout << "你的猜测过大!" << endl;
		}
		else
		{
			cout << "恭喜你猜对了！！" << endl;
			break;
		}
		cout << "请再次输入你猜测的数字：";//再次进行猜测
		cin >> num2;
	}

	system("pause");
	return 0;
}


