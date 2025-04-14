#pragma once
#include <iostream>
#include<string>

#include"baseDMA.h"


using namespace std;

class lacksDMA : public baseDMA
{
private:
    enum {COL_LEN = 40};
    char color[COL_LEN];

public:
    lacksDMA(const char* c = "blank", const char* l = "null", int r = 0);
    lacksDMA(const char* c, const baseDMA& rs);

    friend ostream& operator<<(ostream& os, const lacksDMA& rs);
};

