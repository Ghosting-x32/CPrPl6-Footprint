#ifndef MANAGER_H_
#define MANAGER_H_

#include<iostream>
#include<string>

#include"Worker.h"

using namespace std;

class Manager : public Worker
{
public:
	Manager(int id, string name, int deptid);
	string getDeptName();
	string getGwzz();
	void ShowInfo();

};














#endif 
