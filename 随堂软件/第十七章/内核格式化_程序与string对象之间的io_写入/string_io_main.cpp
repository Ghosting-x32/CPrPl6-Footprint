#include<iostream>
#include<sstream>
#include<string>


using namespace std;



int main()
{
	
	ostringstream outstr;

	string hdisk;
	cout << "what's th name of your hard disk? ";
	getline(cin, hdisk);
	int cap;
	cout << "what's its capacity in GB? ";
	cin >> cap;
	outstr << "The hard disk " << hdisk << " has a cdapacity of "
		<< cap << " gigabytes.\n";

	string result = outstr.str();
	cout << result;






	system("pause");
	return 0;
}