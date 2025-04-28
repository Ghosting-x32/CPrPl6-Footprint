#pragma once
#include<iostream>
#include<string>
#include<random>

#include"Person.h"
#include"Card.h"

using namespace std;

class PokerPlayer : virtual public Person
{

public:
	PokerPlayer(const string& xi = "none", const string& mi = "none");
	Card Draw()const;
	virtual void Show()const;
	virtual void Set();




};