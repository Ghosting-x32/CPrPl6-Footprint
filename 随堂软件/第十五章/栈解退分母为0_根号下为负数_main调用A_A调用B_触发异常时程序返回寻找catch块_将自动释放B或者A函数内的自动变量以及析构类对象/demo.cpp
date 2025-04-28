#include"demo.h"


demo::demo(const string& str)
	:word(str)
{
	cout << "demo " << this->word << " created\n";


}


demo::~demo()
{
	cout << "demo " << this->word << " destroyed\n";

}


void demo::show()const
{
	cout << "demo " << this->word << " lives!\n";

}