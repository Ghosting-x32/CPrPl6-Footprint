#include"Superb.h"

Superb::Superb(int h)
	:Grand(h)
{


}


void Superb::Speak()const
{
	cout << "I am a superb class!!\n";

}


int Superb::Value()const
{
	return Grand::Value();

}


void Superb::Say()const
{
	cout << "I hold the superb value of " << this->Value() << "!\n";

}