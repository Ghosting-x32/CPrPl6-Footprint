#include"RatedPlayer.h"

RatedPlayer::RatedPlayer(unsigned int r, const string& fn, const string& ln, bool ht)
	:TableTennisPlayer(fn, ln, ht), rating(r)
{

}

/*RatedPlayer::RatedPlayer(unsigned int r, const string& fn, const string& ln, bool ht)
{
	TableTennisPlayer(fn, ln, ht);//错误，基类的构造必须在子类之前，成员初始化列表是唯一正确初始化基类和类成员的方式。
	this->rating = r;
}*/


RatedPlayer::RatedPlayer(unsigned int r, const TableTennisPlayer& tp)
	:TableTennisPlayer(tp), rating(r)
{

}


/*RatedPlayer::RatedPlayer(unsigned int r, const TableTennisPlayer& tp)
{
	TableTennisPlayer(tp);//错误，基类的构造必须在子类之前，成员初始化列表是唯一正确初始化基类和类成员的方式。
	this->rating = r;
}*/