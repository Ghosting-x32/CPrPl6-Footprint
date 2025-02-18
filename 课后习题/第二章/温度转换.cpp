#include <iostream>//头文件
double 温度(double);

int main()
{
	using namespace std;     //B表示摄氏温度，A表示华氏温度。
	cout << "Please enter a Celsius value: ";
	double A;
	double B;
	cin >> B;
	A = 温度(B);
	cout << B << " degrees Celsius is " << A << " degrees Fahrenheit.";
	cin.get();
	cin.get();
	return 0;
}

double 温度(double n)
{
	double 华氏温度;
	华氏温度 = n* 1.8 + 32.0;
	return 华氏温度;
}
