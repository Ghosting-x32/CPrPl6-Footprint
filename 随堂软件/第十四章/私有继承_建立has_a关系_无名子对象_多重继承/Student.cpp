#include"Student.h"

Student::Student()
	:string("Null Student"), ArrayDb()
{


}


Student::Student(const string& s)
	:string(s), ArrayDb()
{


}


Student::Student(int n)
	:string("Null"), ArrayDb(n)
{


}


Student::Student(const string& s, int n)
	:string(s), ArrayDb(n)
{


}


Student::Student(const string& s, const ArrayDb& a)
	:string(s), ArrayDb(a)
{


}


Student::Student(const char* str, const double* pd, int n)
	:string(str), ArrayDb(pd, n)
{


}


Student::~Student()
{


}


double Student::Average()const
{
	if (this->ArrayDb::size() > 0)
	{
		return this->ArrayDb::sum() / this->ArrayDb::size();
	}
	else
	{
		cout << "无scores数据！" << endl;
		return 0;
	}

}


const string& Student::Name()const
{
	return (const string&) *this;

}


double& Student::operator[](int i)
{
	return ArrayDb::operator[](i);

}


double Student::operator[](int i)const//const double& Student::operator[](int i)const也可保护数据不被错误修改
{
	return ArrayDb::operator[](i);

}


istream& operator>>(istream& is, Student& stu)
{
	is >> (string&)stu;
	return is;

}


istream& getline(istream& is, Student& stu)
{
	getline(is, (string&)stu);
	return is;

}


ostream& operator<<(ostream& os, const Student& stu)
{
	os << "Scores for " << (const string&)stu << ":\n";
	stu.arr_out(os);
	return os;

}

ostream& Student::arr_out(ostream& os)const
{
	int i;
	int lim = ArrayDb::size();
	if (lim > 0)
	{
		for (i = 0; i < lim; i++)
		{
			os << ArrayDb::operator[](i) << " ";
			if (i % 5 == 4)
			{
				os << endl;
			}

		}
		if (i % 5 != 0)
		{
			os << endl;
		}

	}
	else
	{
		os << " empty array ";

	}

	return os;
}