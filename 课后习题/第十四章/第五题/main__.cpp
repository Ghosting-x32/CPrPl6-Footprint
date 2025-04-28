#include<iostream>
#include<string>

#include"abstr_emp.h"
#include"employee.h"
#include"fink.h"
#include"highfink.h"
#include"manager.h"


using namespace std;



int main()
{
	employee em("Trip", "Harris", "Thumper");
	cout << em << endl;
	em.ShowAll();

	manager ma("Amorphia", "Spindragon", "Nuancer", 5);
	cout << endl << ma << endl;
	ma.ShowAll();

	fink fi("Matt", "Oggs", "Oiler", "Juno Barr");
	cout << endl << fi << endl;
	fi.ShowAll();

	highfink hf(ma, "Curly Kew");
	cout << endl << hf << endl;
	hf.ShowAll();


	cout << "Press a key for next phase:\n";
	cin.get();//按下任意键继续
	highfink hf2;
	hf2.SetAll();

	cout << "Using an abstr_emp* pointer:\n";
	cout << "================================================" << endl;
	abstr_emp* tri[4] = { &em, &fi, &hf, &hf2 };
	for (int i = 0; i < 4; i++)
	{
		tri[i]->ShowAll();
		cout << "================================================" << endl;
	}





	system("pause");
	return 0;
}