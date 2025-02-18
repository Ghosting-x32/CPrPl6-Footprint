#ifndef YHZH_H_
#define YHZH_H_
#include<string>


class Yhzh
{
private:
	std::string name;
	std::string zaha;
	double cuka;
public:
	Yhzh();
	Yhzh(const std::string& mona, const std::string& mozh, double mock = 0.0);
	~Yhzh();
	void show()const;
	void cun(double pr);
	void qu(double pr);
};

#endif