#ifndef GOLF_H_
#define GOLF_H_
#include<string>


class Golf
{
private:
	std::string fullname;
	int handicap;

public:
	Golf();
	Golf(const std::string& ln, const int& pn = 0);
	~Golf();
	void Show()const;
	int setgolf();
	void handicap_s(int hc);
};

#endif