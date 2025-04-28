#include"Grand.h"

Grand::Grand(int h)
{
	this->hold = h;

}


void Grand::Speak()const
{

	cout << "I am a grand class!\n";
}


int Grand::Value()const
{
	return this->hold;

}