#include"Sales.h"

Sales::bad_index::bad_index(int ix, const string& s)
	:logic_error(s)
{
	this->bi = ix;

}


int Sales::bad_index::bi_val()const
{
	return this->bi;

}


Sales::bad_index::~bad_index()
{


}



Sales::Sales(int yy)
{
	this->year = yy;
	for (int i = 0; i < MONTHS; i++)
	{
		this->gross[i] = 0;

	}

}


Sales::Sales(int yy, const double* gr, int n)
{
	this->year = yy;
	int i;
	for (i = 0; i < n; i++)
	{
		this->gross[i] = gr[i];

	}

	for (; i < MONTHS; i++)
	{
		this->gross[i] = 0;

	}

}


Sales::~Sales()
{


}


int Sales::Year()const
{
	return this->year;

}


double Sales::operator[](int i)const
{
	if (i < 0 || i >= MONTHS)
	{
		throw bad_index(i);
	}

	return this->gross[i];
}


double& Sales::operator[](int i)
{
	if (i < 0 || i >= MONTHS)
	{
		throw bad_index(i);
	}

	return this->gross[i];

}