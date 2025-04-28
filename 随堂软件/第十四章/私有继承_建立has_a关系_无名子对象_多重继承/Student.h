#pragma once
#include<iostream>
#include<string>
#include<valarray>

using namespace std;

class Student : private string, private valarray<double>
{
private:
	typedef valarray<double> ArrayDb;
	
	ostream& arr_out(ostream& os)const;



public:
	Student();
	explicit Student(const string& s);
	explicit Student(int n);
	Student(const string& s, int n);
	Student(const string& s, const ArrayDb& a);
	Student(const char* str, const double* pd, int n);

	~Student();

	double Average()const;
	const string& Name()const;
	double& operator[](int i);
	double operator[](int i)const;

	friend istream& operator>>(istream& is, Student& stu);
	friend istream& getline(istream& is, Student& stu);
	friend ostream& operator<<(ostream& os, const Student& stu);







};