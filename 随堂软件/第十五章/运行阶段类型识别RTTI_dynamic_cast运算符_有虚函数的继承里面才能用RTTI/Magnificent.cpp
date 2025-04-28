#include"Magnificent.h"

Magnificent::Magnificent(int h, char c)
	:Superb(h)
{
	this->ch = c;

}


void Magnificent::Speak()const
{
	cout << "I am a magnificent class!!!\n";


}


int Magnificent::Value()const
{
	return Superb::Value();

}


void Magnificent::Say()const
{
	cout << "I hold the character " << this->ch << " and the integer " << this->Value() << "!\n";

}