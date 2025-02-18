#include <iostream>  
#include<cstring>
int main()
{
	using namespace std;
	cout << "Enter your first name: ";
	char charr1[20];
	char charr2[20];
	cin.getline(charr1, 20);
	cout << "Enter your last name: ";
	cin.getline(charr2, 20);
	cout << "Here's the information in a single string: ";
	char pn[3] = ", ";

	char qn1[20];
	char qn2[20];
	char qn3[3];

	strcpy_s(qn1, 20, charr1);
	strcpy_s(qn2, 20, charr2);
	strcpy_s(qn3, 3, pn);

	strcat_s(qn1, qn3);
	strcat_s(qn1, qn2);
	cout<< qn1 << endl;

	cin.get();
	cin.get();
	return 0;
}
