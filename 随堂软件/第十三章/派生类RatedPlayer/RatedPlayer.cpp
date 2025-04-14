#include"RatedPlayer.h"

RatedPlayer::RatedPlayer(unsigned int r, const string& fn, const string& ln, bool ht)
	:TableTennisPlayer(fn, ln, ht), rating(r)
{

}

/*RatedPlayer::RatedPlayer(unsigned int r, const string& fn, const string& ln, bool ht)
{
	TableTennisPlayer(fn, ln, ht);//���󣬻���Ĺ������������֮ǰ����Ա��ʼ���б���Ψһ��ȷ��ʼ����������Ա�ķ�ʽ��
	this->rating = r;
}*/


RatedPlayer::RatedPlayer(unsigned int r, const TableTennisPlayer& tp)
	:TableTennisPlayer(tp), rating(r)
{

}


/*RatedPlayer::RatedPlayer(unsigned int r, const TableTennisPlayer& tp)
{
	TableTennisPlayer(tp);//���󣬻���Ĺ������������֮ǰ����Ա��ʼ���б���Ψһ��ȷ��ʼ����������Ա�ķ�ʽ��
	this->rating = r;
}*/