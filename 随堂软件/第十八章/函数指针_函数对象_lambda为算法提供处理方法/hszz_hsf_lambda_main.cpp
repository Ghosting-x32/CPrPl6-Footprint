#include<iostream>
#include<vector>
#include<algorithm>
#include<random>
#include<cmath>
#include"f_mod.h"

using namespace std;
const long Size1 = 39L;
const long Size2 = 100 * Size1;
const long Size3 = 100 * Size2;

void showint(int n);

bool f3(int x);
bool f13(int x);



int main()
{
	random_device(rd);
	mt19937 gen(rd());

	vector<int> number(Size1);
	generate(number.begin(), number.end(), gen);
	//for_each(number.begin(), number.end(), showint);

	cout << "Sample size = " << Size1 << endl;

	int count3 = count_if(number.begin(), number.end(), f3);//1.使用函数指针（函数名）给算法提供处理方法
	int count13 = count_if(number.begin(), number.end(), f13);
	cout << "Count of numbers divisible by 3: " << count3 << endl;
	cout << "Count of numbers divisible by 13: " << count13 << endl;

	number.resize(Size2);
	generate(number.begin(), number.end(), gen);
	cout << "Sample size = " << Size2 << endl;

	count3 = count_if(number.begin(), number.end(), f_mod(3));//2.使用函数对象（类重写了()符）给算法提供处理方法
	count13 = count_if(number.begin(), number.end(), f_mod(13));
	cout << "Count of numbers divisible by 3: " << count3 << endl;
	cout << "Count of numbers divisible by 13: " << count13 << endl;

	number.resize(Size3);
	generate(number.begin(), number.end(), gen);
	cout << "Sample size = " << Size3 << endl;

	count3 = count_if(number.begin(), number.end(), [](int n) {return n % 3 == 0; });//3.使用lambda函数给算法提供处理方法
	count13 = count_if(number.begin(), number.end(), [](int n) {return n % 13 == 0; });
	cout << "Count of numbers divisible by 3: " << count3 << endl;
	cout << "Count of numbers divisible by 13: " << count13 << endl;






	system("pause");
	return 0;
}


void showint(int n)
{
	cout << n << " ";
}


bool f3(int x)
{

	return x % 3 == 0;

}


bool f13(int x)
{
	return x % 13 == 0;

}