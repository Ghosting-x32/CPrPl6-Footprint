#include<iostream>
#include"stonewt1.h"


int main()
{
	using std::cout;
	Stonewt poppins(9, 2.8);
	poppins.show_lbs();
	double p_wt = poppins;
	cout << "Convert to double => ";
	cout << "Ponppins: " << p_wt << " pounds.\n";
	cout << "Convert to int => ";
	cout << "Poppins: " << int(poppins) << " pounds.\n";

	system("pause");
	return 0;
}

