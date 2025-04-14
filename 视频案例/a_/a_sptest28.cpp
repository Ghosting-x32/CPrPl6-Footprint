#include <iostream>

int main()
{
	using namespace std;
 //三只小猪称体重，比比谁最重
	//1.让用户输入三只小猪的重量
	int num1 = 0;
	int num2 = 0;
	int num3 = 0;
	cout << "请输入小猪A的重量：";
	cin >> num1;
	cout << "请输入小猪B的重量：";
	cin >> num2;
	cout << "请输入小猪C的重量：";
	cin >> num3;
	//2.显示三只小猪的重量
	cout << "小猪A的体重是：" << num1 << endl;
	cout << "小猪B的体重是：" << num2 << endl;
	cout << "小猪C的体重是：" << num3 << endl;
	//3.判断
	if (num1 > num2)//A比B重
	{
		if (num1 > num3)//A比C重
		{
			cout << "小猪A最重！\n";
		}
		else//C比A重
		{
			cout << "小猪C最重！\n";
		}
	}
	else//B比A重
	{
		if (num2 > num3)//B比C重
		{
			cout << "小猪B最重！\n";
		}
		else//C比B重
		{
			cout << "小猪C最重！\n";
		}
	}



	system("pause");
	return 0;
}


