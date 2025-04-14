#pragma once
#include<iostream>
#include<string>
#include<cstring>

using namespace std;

class abcDMA
{

private:
    char* label;
    int rating;

public:
    abcDMA(const char* l = "null", int r = 0);
    abcDMA(const abcDMA& rs);
    virtual ~abcDMA();
    abcDMA& operator= (const abcDMA& rs);
    virtual void View() = 0;







};