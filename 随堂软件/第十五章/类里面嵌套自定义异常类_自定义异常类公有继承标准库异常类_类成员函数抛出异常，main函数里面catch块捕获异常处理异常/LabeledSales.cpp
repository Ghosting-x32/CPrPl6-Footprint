#include"LabeledSales.h"

LabeledSales::nbad_index::nbad_index(const string& lb, int ix, const string& s)
	:bad_index(ix, s), lbl(lb)
{


}


const string& LabeledSales::nbad_index::label_val()const
{

	return this->lbl;
}


LabeledSales::nbad_index::~nbad_index()
{


}



LabeledSales::LabeledSales(const string& lb, int yy)
	:Sales(yy), label(lb)
{


}


LabeledSales::LabeledSales(const string& lb, int yy, const double* gr, int n)
	:Sales(yy, gr, n), label(lb)
{


}


LabeledSales::~LabeledSales()
{


}


const string& LabeledSales::Label()const
{
	return this->label;

}


double LabeledSales::operator[](int i)const
{
	if (i < 0 || i >= MONTHS)
	{
		throw nbad_index(this->label, i);
	}

	return Sales::operator[](i);
}


double& LabeledSales::operator[](int i)
{
	if (i < 0 || i >= MONTHS)
	{
		throw nbad_index(this->label, i);
	}

	return Sales::operator[](i);

}