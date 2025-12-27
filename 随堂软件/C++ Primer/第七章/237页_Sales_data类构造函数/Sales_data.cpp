#include"Sales_data.h"




Sales_data::Sales_data() = default;



Sales_data::Sales_data(const string& s)
	:bookNo(s)
{


}


Sales_data::Sales_data(const string& s, unsigned int n, double p)
	:bookNo(s), units_sold(n), revenue(p *n)
{


}


Sales_data::Sales_data(std::istream& is)
{
	read(is, *this);

}





string Sales_data::isbn()const
{
	return this->bookNo;

}


Sales_data& Sales_data::combine(const Sales_data& sa)
{

	units_sold += sa.units_sold;
	revenue += sa.revenue;

	return *this;
}


double Sales_data::avg_price() const
{
	if (units_sold)
	{
		return revenue / units_sold;
	}
	else
	{
		return 0;
	}

}


Sales_data add(const Sales_data& sa1, const Sales_data& sa2)
{
	Sales_data sum = sa1;
	sum.combine(sa2);
	return sum;

}


std::ostream& print(std::ostream& os, const Sales_data& sa)
{
	os << sa.isbn() << " " << sa.units_sold << " " << sa.revenue << " " << sa.avg_price();

	return os;
}


std::istream& read(std::istream& is, Sales_data& sa)
{
	double price = 0;
	is >> sa.bookNo >> sa.units_sold >> price;

	sa.revenue = price * sa.units_sold;

	return is;
}