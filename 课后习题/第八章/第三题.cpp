#include<iostream>
#include<string>
using namespace std;
void f1(string& ar);


int main()
{
	string csar;
	cout << "Enter a string (q to quit): ";
	while (getline(cin, csar) && csar != "q")
	{
		f1(csar);
		cout << "\nNext string (q to quit): ";
	}



	cout << "Bye.\a\n";
	system("pause");
	return 0;
}

void f1(string& ar)
{
	for (int i = 0; i < ar.size(); i++)
		cout << char(toupper(ar[i]));
}