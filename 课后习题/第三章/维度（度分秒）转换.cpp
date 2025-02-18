#include <iostream>
int main()
{
	using namespace std;
	const int Adf = 60;
	const int Afm = 60;
	double du,fen,miao;
	cout << "Enter a latitude in degrees, minutes, and seconds;\n";
	cout << "First, enter the degrees: ";
	cin >> du;
	cout << "Next, enter the minutes of arc: ";
	cin >> fen;
	cout << "Finally, enter the seconds of arc: ";
	cin >> miao;
	double Q = miao / Afm / Adf;
	double W = fen / Adf;
	double duz = du + W + Q;
	cout << du << " degrees, " << fen << " minutes, " << miao
		<< " seconds = " << duz << " degrees";
	cin.get();
	cin.get();
	return 0;
}
