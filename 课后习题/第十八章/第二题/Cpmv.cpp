#include"Cpmv.h"

Cpmv::Cpmv()
{
	cout << "Ĭ�Ϲ��캯����һ����" << endl;
	this->pi = new Info;
	this->pi->qcode = "q";
	this->pi->zcode = "z";

}


Cpmv::Cpmv(string q, string z)
{
	cout << "��������string����Ĺ��캯����һ����" << endl;
	this->pi = new Info;
	this->pi->qcode = q;
	this->pi->zcode = z;

}


Cpmv::Cpmv(const Cpmv& cp)
{
	cout << "���ƹ��캯����һ����" << endl;
	this->pi = new Info;
	*(this->pi) = *cp.pi;
	
}


Cpmv::Cpmv(Cpmv&& mv)
{
	cout << "�ƶ����캯����һ����" << endl;
	this->pi = mv.pi;
	mv.pi = nullptr;

}


Cpmv::~Cpmv()
{
	cout << "����������һ����" << endl;
	if (this->pi != nullptr)
	{
		delete pi;
		this->pi = nullptr;
	}
	
}


Cpmv& Cpmv::operator=(const Cpmv& cp)
{
	cout << "��ֵ�����������һ����" << endl;
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
	cout << "�ƶ���ֵ�����������һ����" << endl;
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
	cout << "�ӷ������������һ����" << endl;
	Cpmv temp;
	temp.pi->qcode = this->pi->qcode + obj.pi->qcode;
	temp.pi->zcode = this->pi->zcode + obj.pi->zcode;


	return temp;
}


void Cpmv::Display()const
{
	cout << "չʾ������һ����" << endl;

	cout << "qcode: " << this->pi->qcode << endl;
	cout << "zcode: " << this->pi->zcode << endl;

}
