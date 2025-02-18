#include <iostream>           //指针和字符串
#include<cstring>
int main()
{
	using namespace std;
	char animal[20] = "bear";
	char animal1[20];
	const char* bird = "wren";
	char* ps;

	strcpy_s(animal1, 20, animal);//strcpy_s新用法
	cout << animal1 << endl;

	cout << animal << " and ";
	cout << bird << "\n";

	cout << "Enter a kind of animal; ";
	cin >> animal;

	ps = animal;
	cout << ps << "!\n";
	cout << "Before using strcpy():\n";
	cout << animal << " at " << (int*)animal << endl;
	cout << ps << " at " << (int*)ps << endl;

	ps = new char[strlen(animal) + 1];
	strcpy_s(ps,20, animal);       //strcpy_s新用法
	cout << "After using strcpy():\n";
	cout << animal << " at " << (int*)animal << endl;
	cout << ps << " at " << (int*)ps << endl;
	delete[] ps;
	cin.get();
	cin.get();
	return 0;
}
