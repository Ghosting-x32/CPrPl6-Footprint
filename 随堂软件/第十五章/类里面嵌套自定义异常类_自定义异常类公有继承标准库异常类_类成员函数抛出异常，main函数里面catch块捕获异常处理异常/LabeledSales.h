#pragma once
#include<iostream>
#include<string>
#include<stdexcept>

#include"Sales.h"

using namespace std;

class LabeledSales : public Sales
{
public:
	class nbad_index : public bad_index
	{
	private:
		string lbl;

	public:
		nbad_index(const string& lb, int ix, const string& s = "Index error in LabeledSales object\n");
		const string& label_val()const;
		virtual~nbad_index();

	};


	explicit LabeledSales(const string& lb = "none", int yy = 0);
	LabeledSales(const string& lb, int yy, const double* gr, int n);
	virtual~LabeledSales();
	const string& Label()const;
	virtual double operator[](int i)const;
	virtual double& operator[](int i);






private:
	string label;

};