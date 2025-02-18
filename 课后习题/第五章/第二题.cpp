#include<iostream>
#include<array>
const int ArSize = 101;
int main()
{
	using namespace std;
	cout.setf(ios_base::fixed, ios_base::floatfield);
	array<long double, 101>factorials;
	factorials[1] = factorials[0] = 1L;
	for (int i = 2; i < ArSize; i++)
		factorials[i] = i * factorials[i - 1];
	for (int i = 0; i < ArSize; i++)
		cout << i << "! = " << factorials[i] << endl;

	cin.get();
	cin.get();
	return 0;
}