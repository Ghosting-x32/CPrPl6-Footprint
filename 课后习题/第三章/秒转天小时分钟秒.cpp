#include <iostream>
int main()
{
	using namespace std;
	const int Axf = 60;
	const int Afm = 60;
	const int Atx = 24;
	long long miao;
	cout << "Enter the number of seconds: ";
	cin >> miao;
	int ta, xs, fz, miao1;
	miao1 = miao % Afm;
	fz = miao / Afm % Axf;
	xs = miao / Afm / Axf % Atx;
	ta = miao / Afm / Axf / Atx;
	cout << miao << " seconds = " << ta << " days, "
		<< xs << " hours, " << fz << " minutes, "
		<< miao1 << " seconds";
	cin.get();
	cin.get();
	return 0;
}
