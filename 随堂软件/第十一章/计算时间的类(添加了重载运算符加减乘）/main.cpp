#include<iostream>
#include"mytime2.h"


int main()
{

	using std::cout;
	using std::endl;
	Time weeding(4, 35);
	Time waxing(2, 47);
	Time total;
	Time diff;
	Time adjusted;

	cout << "weeding time = ";
	weeding.Show();
	cout << endl;

	cout << "waxing time = ";
	waxing.Show();
	cout << endl;

	total = weeding + waxing;
	cout << "weeding + waxing = ";
	total.Show();
	cout << endl;

	diff = weeding - waxing;
	cout << "weeding - waxing = ";
	diff.Show();
	cout << endl;

	adjusted = total * 1.5;
	cout << "adjusted work time = ";
	adjusted.Show();
	cout << endl;

	system("pause");
	return 0;
}
