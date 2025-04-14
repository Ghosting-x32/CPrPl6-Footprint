#ifndef RATEDPLAYER_H_
#define RATEDPLAYER_H_
#include<iostream>
#include<string>

#include"TableTennisPlayer.h"

using namespace std;

class RatedPlayer : public TableTennisPlayer
{
private:
	unsigned int rating;


public:
	RatedPlayer(unsigned int r = 0, const string& fn = "none", const string& ln = "none", bool ht = false);
	RatedPlayer(unsigned int r, const TableTennisPlayer& tp);
	unsigned int Rating()const { return rating; };
	void ReseRating(unsigned int r) { rating = r; };

};





#endif 

