#include<iostream>
using namespace std;

template <typename T>
T max5(T ar[5]);






int main()
{
	int ar1[5] = { 1,2,3,4,5 };
	double ar2[5] = { 2.3,3.3,4.3,5.3,6.3 };
	cout << max5(ar1) << endl;
	cout << max5(ar2) << endl;







	system("pause");
	return 0;
}

template <typename T>
T max5(T ar[5])
{
	T temp = ar[0];
	for (int i = 0; i < 5; i++)
		temp = temp > ar[i + 1] ? temp : ar[i + 1];
	return temp;
}
