#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_

#include<iostream>
#include<string>

#include"Worker.h"

using namespace std;

class Employee : public Worker
{
public:
	Employee(int id, string name, int deptid);
	string getDeptName();
	string getGwzz();
	void ShowInfo();

};














#endif 
