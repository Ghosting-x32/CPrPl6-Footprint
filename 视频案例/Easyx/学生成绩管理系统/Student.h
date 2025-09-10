#pragma once
#include<string>
#include<sstream>



class Student
{
public:
	Student();
	Student(unsigned int number, std::string name,std::string grade, unsigned int math, unsigned int chinese, unsigned int englisg);

	std::string formatInfo();
	static Student fromString(const std::string& str);



public:
	unsigned int m_number;
	std::string m_name;
	std::string m_grade;
	unsigned int m_math;
	unsigned int m_chinese;
	unsigned int m_english;





};

