#pragma once
#include<iostream>
#include<string>
#include<cstring>


using namespace std;

class Cd
{
private:
    char performers[50];
    char label[20];
    int selections;
    double playtime;



public:
    Cd(const char* s1 = "s1", const char* s2 = "s2", int n = 0, double x = 0.0);
    virtual ~Cd(){}
    virtual void Report()const;

    
};



