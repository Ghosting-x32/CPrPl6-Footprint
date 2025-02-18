#include<iostream>
const double Dys = 100;
const double Cys = 100;
const double Dll = 0.1;
const double Cll = 0.05;
int main()
{
	using namespace std;
	int year;
	double* Dyl = new double[100];
	Dyl[0] = Dll * Dys + Dys;
	double* Cgnyl = new double[100];
	Cgnyl[0] = Cll * Cys + Cys;
	double* xc = new double[100];
	xc[0] = Cgnyl[0] - Dyl[0];

	for (year = 1; year < 99; ++year)
	{
		Cgnyl[year] = Cgnyl[year - 1] * Cll + Cgnyl[year - 1];
		Dyl[year] = Dll * Dys * (year + 1) + Dys;
	}

	for (year = 0; Cgnyl[year] - Dyl[year] < 0; ++year)
		xc[year] = Cgnyl[year] - Dyl[year];

	cout << "经过" << year + 1 << "年后，Cleo超过Daphne." << endl;
	cout << "Daphne的收入（本息）是: " << Dyl[year] << "美元。" << endl;
	cout << "Cleo的收入（本息）是: " << Cgnyl[year] << "美元。" << endl;
	cout << "相差: " << Cgnyl[year] - Dyl[year] << "美元。";

	delete[] Cgnyl;
	delete[] Dyl;
	delete[] xc;

	cin.get();
	cin.get();
	return 0;
}