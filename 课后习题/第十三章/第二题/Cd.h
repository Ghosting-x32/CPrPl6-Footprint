#pragma once
#include<iostream>
#include<string>
#include<cstring>


using namespace std;

class Cd
{
private:
    char* performers;
    char* label;
    int selections;
    double playtime;



public:
    Cd(const char* s1 = "s1", const char* s2 = "s2", int n = 0, double x = 0.0);
    Cd(const Cd& cd1);
    virtual ~Cd();
    virtual void Report()const;

    Cd& operator=(const Cd& cd1);
};



