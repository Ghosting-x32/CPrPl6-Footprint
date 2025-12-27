#include"Person.h"


string Person::rt_name()const
{

	return this->name_n;
}


string Person::rt_address()const
{

	return address_a;
}

std::ostream& print(std::ostream& os, const Person& per)
{
	os << per.rt_name() << " " << per.rt_address();

	return os;
}


std::istream& read(std::istream& is, Person& per)
{
	is >> per.name_n >> per.address_a;

	return is;
}