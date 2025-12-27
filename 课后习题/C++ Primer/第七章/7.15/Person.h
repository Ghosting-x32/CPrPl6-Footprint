#pragma once
#include<string>
#include<iostream>

using std::string;



struct Person
{
	string name_n;
	string address_a;


	Person();
	Person(const string& s);
	Person(const string& s1, const string& s2);
	Person(std::istream& is);





	string rt_name()const;
	string rt_address()const;




};

std::ostream& print(std::ostream& os, const Person& per);
std::istream& read(std::istream& is, Person& per);


