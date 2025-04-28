#pragma once
#include<iostream>
#include<string>
#include<stdexcept>

using namespace std;

class Sales
{
public:
	enum {MONTHS = 12};

	class bad_index : public logic_error
	{
	private:
		int bi;

	public:
		explicit bad_index(int ix, const string& s = "Index error in Sales object\n");
		int bi_val()const;
		virtual ~bad_index();


	};

	explicit Sales(int yy = 0);
	Sales(int yy, const double* gr, int n);
	virtual ~Sales();
	int Year()const;
	virtual double operator[](int i)const;
	virtual double& operator[](int i);









private:
	double gross[MONTHS];
	int year;



};