#include<iostream>
#include<vector>
#include<algorithm>
#include<random>
#include<cmath>
#include<ctime>
#include<chrono>


using namespace std;
const long Size1 = 390000L;


void showint(int n);



int main()
{
	auto time_seed = static_cast<unsigned int>(chrono::high_resolution_clock::now().time_since_epoch().count());//获取高精度时间戳（微秒级）
	random_device(rd);
	mt19937 gen(rd() ^ time_seed);

	vector<int> number(Size1);
	generate(number.begin(), number.end(), gen);
	int temp = number.back();
	int temp1 = number.front();



	cout << "Sample size = " << Size1 << endl;

	int count3 = count_if(number.begin(), number.end(), [](int n) {return n % 3 == 0; });	
	cout << "Count of numbers divisible by 3: " << count3 << endl;

	int count13 = 0;
	for_each(number.begin(), number.end(), [&count13](int n) {count13 += n % 13 == 0; });//lambda函数中，作用域内的单个变量的引用被用于中括号中
	cout << "Count of numbers divisible by 13: " << count13 << endl;


	auto time_seed1 = static_cast<unsigned int>(chrono::high_resolution_clock::now().time_since_epoch().count());//获取高精度时间戳（微秒级）
	mt19937 gen1(rd() ^ time_seed1);//刷新系统时间戳，不一样的时间生成不一样的随机number,使得number里面的内容不一样


	count3 = count13 = 0;
	vector<int> number1(Size1);
	generate(number1.begin(), number1.end(), gen1);

	int temp2 = number1.back();
	int temp3 = number1.front();

	for_each(number1.begin(), number1.end(), [&](int n) {count3 += n % 3 == 0; count13 += n % 13 == 0; });//lambda函数中，作用域内的所有变量的引用被用于中括号中
	cout << "Count of numbers divisible by 3: " << count3 << endl;
	cout << "Count of numbers divisible by 13: " << count13 << endl;



	cout << temp1 << endl << temp << endl << endl << temp3 << endl << temp2 << endl;//验证两个number（vector对象）的头和尾都不一样



	system("pause");
	return 0;
}

void showint(int n)
{
	cout << n << endl;
}
