#ifndef STACK_H_
#define STACK_H_

struct customer
{
	char fullname[35] = "";
	double payment = 0.0;
};

typedef customer Item;

class Stack
{
private:
	enum {MAX = 10};
	Item items[MAX];
	int top;
public:
	Stack();
	~Stack();
	bool isempty()const;
	bool isfull()const;
	bool push(const Item& item);
	bool pop(Item& item);
};




#endif