#ifndef BRASS_H_
#define BRASS_H_
#include <iostream>
#include<string>

using namespace std;

class Brass
{
private:
    string fullName;
    long acctNum;
    double balance;

public:
    Brass(const string& s = "Nullbody", long an = -1, double bal = 0.0);
    void Deposit(double amt);
    virtual void Withdraw(double amt);
    double Banlance()const;
    virtual void ViewAcct() const;
    virtual ~Brass(){}


};
#endif
