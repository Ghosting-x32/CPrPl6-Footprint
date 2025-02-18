#include<iostream>
#include"stonewt.h"
using std::cout;

void display(const Stonewt& st, int n);

int main()
{
	Stonewt incognito = 275;
	Stonewt wolfe(285.7);
	Stonewt taft(21, 8);

	cout << "The celebrity weighed ";
	cout << incognito;
	incognito.setstztIS();
	cout << "分开显示的incognito: " << incognito;
	cout << "The detective weighed " << wolfe;
	cout << "显示整型的wolfe: ";
	wolfe.setstztIP();
	cout << wolfe;
	cout << "The President weighed "
		<< taft;

	cout << "wolfe + taft = ";
	cout << wolfe + taft;
	Stonewt temp = wolfe - incognito;
	cout << "wolfe - incognito = ";
	temp.setstztIS();
	cout << temp;

	cout << "taft * 2.1 = ";
	Stonewt temp1 = taft * 2.1;
	temp1.setstztIS();
	cout << temp1;

	cout << "3.6 * wolfe = ";
	Stonewt temp2 = 3.6 * wolfe;
	temp2.setstztIS();
	cout << temp2;

	display(taft, 2);
	cout << "The wrestler weighed even more.\n";
	display(422, 2);
	cout << "No stone left unearned\n";










	system("pause");
	return 0;
}

void display(const Stonewt& st, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Wow! ";
		cout << st;
	}
}