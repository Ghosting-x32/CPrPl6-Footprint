#include <iostream>
#include<string>

#include"Brass.h"
#include"BrassPlus.h"


using namespace std;

typedef ios_base::fmtflags format;
typedef streamsize precis;
format setFormat();
void restore(format f, precis p);

int main()
{
	format initialState = setFormat();
	precis prec = cout.precision(2);

	Brass Piggy("Porcelot Pigg", 381299, 4000.00);
	BrassPlus Hoggy("Horatio Hogg", 382288, 3000.00);
	Piggy.ViewAcct();
	cout << endl;
	Hoggy.ViewAcct();
	cout << endl;

	cout << "Depositing $1000 into the Hogg Account:\n";
	Hoggy.Deposit(1000.00);
	cout << "New balance: $" << Hoggy.Banlance() << endl << endl;

	cout << "Withdrawing $4200.00 from the Pigg Account:\n";
	Piggy.Withdraw(4200.00);
	cout << "Piggy account balance: $" << Piggy.Banlance() << endl << endl;

	cout << "Withdrawing $4200.00 from the Hogg Account:\n";
	Hoggy.Withdraw(4200.00);
	Hoggy.ViewAcct();

	restore(initialState, prec);

	system("pause");
	return 0;
}


format setFormat()
{
	return cout.setf(ios_base::fixed, ios_base::floatfield);
}


void restore(format f, precis p)
{
	cout.setf(f, ios_base::floatfield);
	cout.precision(p);
}