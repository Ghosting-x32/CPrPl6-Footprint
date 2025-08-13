#include"Cpmv.h"

Cpmv::Cpmv()
{
	cout << "默认构造函数走一个！" << endl;
	this->pi = new Info;
	this->pi->qcode = "q";
	this->pi->zcode = "z";

}


Cpmv::Cpmv(string q, string z)
{
	cout << "接受两个string对象的构造函数走一个！" << endl;
	this->pi = new Info;
	this->pi->qcode = q;
	this->pi->zcode = z;

}


Cpmv::Cpmv(const Cpmv& cp)
{
	cout << "复制构造函数走一个！" << endl;
	this->pi = new Info;
	*(this->pi) = *cp.pi;
	
}


Cpmv::Cpmv(Cpmv&& mv)
{
	cout << "移动构造函数走一个！" << endl;
	this->pi = mv.pi;
	mv.pi = nullptr;

}


Cpmv::~Cpmv()
{
	cout << "析构函数走一个！" << endl;
	if (this->pi != nullptr)
	{
		delete pi;
		this->pi = nullptr;
	}
	
}


Cpmv& Cpmv::operator=(const Cpmv& cp)
{
	cout << "赋值运算符函数走一个！" << endl;
	if (this == &cp)
	{
		return *this;
	}

	delete this->pi;
	this->pi = new Info;
	*(this->pi) = *cp.pi;
	return *this;
}


Cpmv& Cpmv::operator=(Cpmv&& mv)
{
	cout << "移动赋值运算符函数走一个！" << endl;
	if (this == &mv)
	{
		return *this;
	}

	delete this->pi;
	this->pi = mv.pi;
	mv.pi = nullptr;

	return *this;

}


Cpmv Cpmv::operator+(const Cpmv& obj)const
{
	cout << "加法运算符函数走一个！" << endl;
	Cpmv temp;
	temp.pi->qcode = this->pi->qcode + obj.pi->qcode;
	temp.pi->zcode = this->pi->zcode + obj.pi->zcode;


	return temp;
}


void Cpmv::Display()const
{
	cout << "展示函数走一个！" << endl;

	cout << "qcode: " << this->pi->qcode << endl;
	cout << "zcode: " << this->pi->zcode << endl;

}
