#include"Tv.h"

Tv::Tv(int s, int mc)
{
	this->state = s;
	this->volume = 5;
	this->maxchannel = mc;
	this->channel = 2;
	this->mode = Cable;
	this->input = TV;

}


void Tv::onoff()
{
	this->state = (this->state == On) ? Off : On;

}


bool Tv::ison()const
{
	return this->state == On;

}


bool Tv::volup()
{
	if (this->volume < MaxVal)
	{
		this->volume++;
		return true;

	}
	else
	{
		return false;
	}

}


bool Tv::voldown()
{
	if (this->volume > MinVal)
	{
		this->volume--;
		return true;

	}
	else
	{
		return false;
	}

}


void Tv::chanup()
{
	if (this->channel < this->maxchannel)
	{
		this->channel++;
	}
	else
	{
		this->channel = 1;
	}

}


void Tv::chandown()
{
	if (this->channel > 1)
	{
		this->channel--;
	}
	else
	{
		this->channel = this->maxchannel;
	}

}


void Tv::set_mode()
{
	this->mode = (this->mode == Antenna) ? Cable : Antenna;

}


void Tv::set_input()
{

	this->input = (this->input == TV) ? DVD : TV;
}


void Tv::settings()
{
	cout << "TV is " << (this->state == Off ? "Off" : "On") << endl;

	if (this->ison())
	{
		cout << "Volume setting = " << this->volume << endl;
		cout << "Channel setting = " << this->channel << endl;
		cout << "Mode = " << (this->mode == Antenna ? "antenna" : "cable") << endl;
		cout << "Input = " << (this->input == TV ? "TV" : "DVD") << endl;

	}

}