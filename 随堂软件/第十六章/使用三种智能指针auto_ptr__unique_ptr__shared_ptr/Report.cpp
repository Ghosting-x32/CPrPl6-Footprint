#include"Report.h"

Report::Report(const string& s)
	:str(s)
{
	cout << "Object created!\n";

}


Report::~Report()
{
	cout << "Object deleted!\n";

}


void Report::comment()const
{
	cout << this->str << "\n";

}