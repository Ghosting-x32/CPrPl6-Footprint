#include"Person.h"

Person::Person(const string& xi, const string& mi)
	:m_Xing(xi), m_ming(mi)
{


}


void Person::Show()const
{

	cout << "xing: " << this->m_Xing << "\tming: " << this->m_ming << endl;
}

void Person::Set()
{
	cout << "������xing:";
	cin >> this->m_Xing;
	cout << "������ming: ";
	cin >> this->m_ming;

}


Person::~Person()
{


}