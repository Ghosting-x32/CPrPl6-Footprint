#include"Sales_data.h"


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


}


std::ostream& print(std::ostream& os, const Sales_data& sa)
{


}


std::istream& read(std::istream& is, const Sales_data& sa)
{


}