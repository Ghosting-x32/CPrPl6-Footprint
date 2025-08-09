#pragma once
#include<iostream>
#include<string>

using namespace std;

class Report
{
private:

	string str;

public:
	Report(const string& s);
	~Report();
	void comment()const;




};