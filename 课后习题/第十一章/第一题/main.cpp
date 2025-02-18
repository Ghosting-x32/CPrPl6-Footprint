#include<iostream>
#include<cstdlib>
#include<ctime>
#include<fstream>
#include"vect.h"


int main()
{
	using namespace std;
	ofstream fout;
	ofstream fout1;
	fout.open("thewalk.txt");
	fout1.open("thewalk1.txt");
	using VECTOR::Vector;
	srand(time(0));
	double direction;
	Vector step;
	Vector result(0.0, 0.0);
	unsigned long steps = 0;
	double target;
	double dstep;
	fout1 << "Enter target distance (q to quit): " << endl;
	cout << "Enter target distance (q to quit): ";
	while (cin >> target)
	{
		fout1 << "Enter step length: " << endl;
		cout << "Enter step length: ";
		if (!(cin >> dstep))
			break;

		while (result.magval() < target)
		{
			direction = rand() % 360;
			step.reset(dstep, direction, Vector::POL);
			result.polar_mode();
			fout << result << endl;
			result = result + step;
			steps++;
		}
		result.polar_mode();
		fout << result << endl;
		fout1 << "After " << steps << " steps, the subject "
			"has the following location:\n";
		cout << "After " << steps << " steps, the subject "
			"has the following location:\n";
		result.rect_mod();
		fout1 << result << endl;
		cout << result << endl;
		result.polar_mode();
		fout1 << " or\n" << result << endl;
		cout << " or\n" << result << endl;
		fout1 << "Average outward distance per step = "
			<< result.magval() / steps << endl;
		cout << "Average outward distance per step = "
			<< result.magval() / steps << endl;
		steps = 0;
		result.reset(0.0, 0.0);
		fout1 << "Enter target distance (q to quit): " << endl;
		cout << "Enter target distance (q to quit): ";
	}
	fout1 << "Bye!\n";
	cout << "Bye!\n";
	cin.clear();
	while (cin.get() != '\n')
		continue;














	system("pause");
	return 0;
}
