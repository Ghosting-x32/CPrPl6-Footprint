#pragma once
#include<iostream>
#include<string>
#include<cstring>

using namespace std;

class baseDMA
{
private:
    char* label;
    int rating;

public:
    baseDMA(const char* l = "null", int r = 0);
    baseDMA(const baseDMA& rs);
    virtual ~baseDMA();
    baseDMA& operator= (const baseDMA & rs);
    friend ostream& operator<<(ostream& os, const baseDMA& rs);




    
};



