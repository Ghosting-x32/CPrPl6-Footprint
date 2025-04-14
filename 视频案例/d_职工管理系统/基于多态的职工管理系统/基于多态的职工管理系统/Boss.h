#ifndef BOSS_H_
#define BOSS_H_

#include<iostream>
#include<string>

#include"Worker.h"

using namespace std;

class Boss : public Worker
{
public:
	Boss(int id, string name, int deptid);
	string getDeptName();
	string getGwzz();
	void ShowInfo();

};














#endif 
