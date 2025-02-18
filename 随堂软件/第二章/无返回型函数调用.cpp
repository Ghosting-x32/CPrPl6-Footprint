#include <iostream>
void simo(int);
int main()
{
	using namespace std;
	simo(3);
	cout << "Pick an integer: ";
	int count;
	cin >> count;
	simo(count);
	cout << "Done!" << endl;
	cin.get();
	cin.get();
	return 0;
}

void simo(int n)
{
	using namespace std;
	cout << "Simon says touch your toes " << n << " times." << endl;
}