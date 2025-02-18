#include<iostream>
#include"stock10.h"


int main()
{
	{
		using std::cout;
		cout << "Using constructors to create new objects\n";
		Stock stock1("NanoSmart", 12, 20.0);
		cout << stock1;
		Stock stock2 = Stock("Boffo Objects", 2, 2.0);
		cout << stock2;

		cout << "Assigning stock1 to stock2:\n";
		stock2 = stock1;
		cout << "Listing stock1 and stock2:\n";
		cout << stock1;
		cout << stock2;

		cout << "Using a constructor to reset an object\n";
		stock1 = Stock("Nifty Foods", 10, 50.0);
		cout << "Rebised stock1:\n";
		cout << stock1;
		cout << "Done\n";
	}


	system("pause");
	return 0;
}
