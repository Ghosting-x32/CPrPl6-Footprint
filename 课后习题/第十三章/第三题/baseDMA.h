#pragma once
#include<iostream>
#include<string>
#include<cstring>

#include"abcDMA.h"

using namespace std;

class baseDMA : public abcDMA
{
private:
    int m_text;

public:
    baseDMA(int text = 0, const char* l = "null", int r = 0);
   
    virtual void View();




    
};



