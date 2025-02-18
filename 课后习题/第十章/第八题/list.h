#ifndef LIST_H_
#define LIST_H_
#include<string>
struct Qbll
{
	std::string name = "";
	int SL = 0;
};
typedef Qbll Item;

class List
{
private:
	static const int MZ = 10;
	Item darunf[MZ];
	int top;
public:
	List();
	~List();
	bool tianj(const Item& n);
	bool sfkong()const;
	bool sfman()const;
	void visit(void (*pf)(Item&));
	
};




#endif