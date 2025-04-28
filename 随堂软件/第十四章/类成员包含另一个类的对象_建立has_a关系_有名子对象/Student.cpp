#include"Student.h"

Student::Student()
	:name("Null Student"), scores()
{


}


Student::Student(const string& s)
	:name(s), scores()
{


}


Student::Student(int n)
	:name("Null"), scores(n)
{


}


Student::Student(const string& s, int n)
	:name(s), scores(n)
{


}


Student::Student(const string& s, const ArrayDb& a)
	:name(s), scores(a)
{


}


Student::Student(const char* str, const double* pd, int n)
	:name(str), scores(pd, n)
{


}


Student::~Student()
{


}


double Student::Average()const
{
	if (this->scores.size() > 0)
	{
		return this->scores.sum() / this->scores.size();
	}
	else
	{
		cout << "无scores数据！" << endl;
		return 0;
	}

}


const string& Student::Name()const
{
	return this->name;

}


double& Student::operator[](int i)
{
	return this->scores[i];

}


double Student::operator[](int i)const//const double& Student::operator[](int i)const也可保护数据不被错误修改
{
	return this->scores[i];

}


istream& operator>>(istream& is, Student& stu)
{
	is >> stu.name;
	return is;

}


istream& getline(istream& is, Student& stu)
{
	getline(is, stu.name);
	return is;

}


ostream& operator<<(ostream& os, const Student& stu)
{
	os << "Scores for " << stu.name << ":\n";
	stu.arr_out(os);
	return os;

}

ostream& Student::arr_out(ostream& os)const
{
	int i;
	int lim = this->scores.size();
	if (lim > 0)
	{
		for (i = 0; i < lim; i++)
		{
			os << this->scores[i] << " ";
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