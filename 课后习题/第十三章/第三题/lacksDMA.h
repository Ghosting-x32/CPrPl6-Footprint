#pragma once
#include <iostream>
#include<string>

#include"abcDMA.h"


using namespace std;

class lacksDMA : public abcDMA
{
private:
    enum {COL_LEN = 40};
    char color[COL_LEN];

public:
    lacksDMA(const char* c = "blank", const char* l = "null", int r = 0);
    lacksDMA(const char* c, const abcDMA& rs);

    virtual void View();
};

