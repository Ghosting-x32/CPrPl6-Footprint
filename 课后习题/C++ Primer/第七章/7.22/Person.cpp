#include"Person.h"


Person::Person() = default;



Person::Person(const string& s)
	:name_n(s)
{


}


Person::Person(const string& s1, const string& s2)
	:name_n(s1), address_a(s2)
{


}


Person::Person(std::istream& is)
{
	read(is, *this);

}





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
	os << per.rt_name() << "\n" << per.rt_address();

	return os;
}


std::istream& read(std::istream& is, Person& per)
{
	//is >> per.name_n >> per.address_a;

	getline(is, per.name_n);
	getline(is, per.address_a);


	return is;
}