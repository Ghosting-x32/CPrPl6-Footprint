#pragma once
#include<iostream>
#include<string>

using std::cout;
using std::cin;
using std::endl;
using std::string;




struct Sales_data
{
	string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;

	string isbn()const;
	Sales_data& combine(const Sales_data& sa);
	double avg_price() const;




};


Sales_data add(const Sales_data& sa1, const Sales_data& sa2);
std::ostream& print(std::ostream& os, const Sales_data& sa);
std::istream& read(std::istream& is, Sales_data& sa);