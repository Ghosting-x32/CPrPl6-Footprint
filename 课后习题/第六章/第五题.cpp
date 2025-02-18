#include<iostream>
int main()
{
	using namespace std;
    long sr;
	double ss;
	cout << "请输入你的整数收入：";
	while (cin >> sr && sr > 0)
	{
		if (sr <= 5000)
		{
			cout << "不收税！";
        }
		else if (sr > 5000 && sr <= 15000)
		{
			ss = (sr - 5000) * 0.10;
			cout << "税收为：" << ss << "tvarp!";
		}
		else if (sr > 15000 && sr <= 35000)
		{
			ss = (sr - 15000) * 0.15 + 1000;
			cout << "税收为：" << ss << "tvarp!";
		}
		else
		{
			ss = (sr - 35000) * 0.20 + 1000 + 3000;
			cout << "税收为：" << ss << "tvarp!";
		}
		cout << "\n请输入你的下一个整数收入：";
	}
	cout << "Bye!!" << endl;

	system("pause");
	return 0;
}


