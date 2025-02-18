#include <iostream>           
int main()
{
	using namespace std;
	cout << "What is your first name? ";
	char charr1[20];
	char charr2[20];
	cin.getline(charr1, 20);
	cout << "What is your last name? ";
	cin.getline(charr2,20);
	cout << "What letter grade do you deserve? ";
	char cj1;
	char cj2;
	cin >> cj1;
	cout << "What is your age? ";
	int age;
	cin >> age;
	cout << "Name: " << charr2 << ", " << charr1 << endl;
	cj2 = cj1 + 1;
	cout << "Grade: " << cj2 << endl;
	cout << "Age: " << age << endl;
	cin.get();
	cin.get();
	return 0;
}
