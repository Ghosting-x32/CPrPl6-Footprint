#include<iostream>
double 时间转换(double);



int main()
{
	using  namespace std; //A表示天文单位。
	cout << "啊Enter the number of light years : ";
	double 光年单位;
	cin >> 光年单位;
	double A;
	A = 时间转换(光年单位);
	cout << 光年单位 << " light years = " << A << " astronomical units.";
	cin.get();
	cin.get();
	return 0;
}

double 时间转换(double n)
{
	double 天文单位;
	天文单位 = n * 63240;
	return 天文单位;
}
