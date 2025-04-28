#pragma once
#include<iostream>
#include<string>

#include"Person.h"
#include"Gunslinger.h"
#include"PokerPlayer.h"
#include"Card.h"

using namespace std;

class BadDude : public Gunslinger, public PokerPlayer
{

public:
	BadDude(int num = 0, const string& xi = "none", const string& mi = "none");

	virtual void Show()const;
	Card Cdraw()const;
	double Gdraw()const;
	virtual void Set();

};