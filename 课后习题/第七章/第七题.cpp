#include<iostream>
const int Max = 5;
double* fill_array(double* begin, double* end);
void show_array(const double* begin1, const double* end1);
void revalue(double r, double* begin2, double* end2);
int main()
{
	using namespace std;
	double properties[Max];
	double* size = fill_array(properties, properties + Max);
	show_array(properties, size);
	cout << "Enter revaluation factor: ";
	double factor;
	while (!(cin >> factor))
	{
		cin.clear();
		while (cin.get() != '\n')
			continue;
		cout << "Bad input; Please enter a number: ";
	}
		revalue(factor, properties, size);
		show_array(properties, size);

	cout << "Done.\a\a\n";


	system("pause");
	return 0;
}

double* fill_array(double* begin, double* end)
{
	using namespace std;
	double* pt;
	int i = 0;
	for (pt = begin; pt != end; pt++)
	{
		cout << "Enter value #" << i + 1 << ":";
		i++;
		cin >> *pt;
		if (!cin)
		{
			cin.clear();
			while (cin.get() != '\n')
				continue;
			cout << "Bad input; input process terminated.\n";
			break;
		}
		else if (*pt < 0)
			break;
	}
	return pt;
}

void show_array(const double* begin1, const double* end1)
{
	using namespace std;
	const double* pn;
	int i = 0;
	for (pn = begin1; pn != end1; pn++)
	{
		cout << "Property #" << i + 1 << ": $";
		i++;
		cout << *pn << endl;
	}
}

void revalue(double r, double* begin2, double* end2)
{
	double* ps;
	for (ps = begin2; ps != end2; ps++)
		*ps *= r;
}