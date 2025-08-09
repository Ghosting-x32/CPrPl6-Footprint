#include<iostream>
#include<sstream>
#include<string>


using namespace std;



int main()
{
	
	string lit = "It was a dark and stormy day, and "
		" the full moon glowed brilliantly.";
	istringstream instr(lit);
	string word;
	while (instr >> word)
	{
		cout << word << endl;
	}






	system("pause");
	return 0;
}