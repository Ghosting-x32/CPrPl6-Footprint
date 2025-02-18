#ifndef PLORG_H_
#define PLORG_H_


class Plorg
{
private:
	static const int MZ = 19;
	char name[MZ];
	int CI;
public:
	Plorg(const char ar[] = "Plorga", int n = 50);
	~Plorg();
	void gnexi(int n);
	void show();
};




#endif