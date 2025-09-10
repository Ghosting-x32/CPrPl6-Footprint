#include "Student.h"


Student::Student()
{



}



Student::Student(unsigned int number, std::string name, std::string grade, unsigned int math, unsigned int chinese, unsigned int english)
	:m_number(number),m_name(name),m_grade(grade),m_math(math),m_chinese(chinese),m_english(english)
{



}

std::string Student::formatInfo()//格式化输出
{
	std::stringstream ss;
	ss << m_number << "\t" << m_name << "\t" << m_grade << "\t" << m_math << "\t" << m_chinese << "\t" << m_english << std::endl;

	return ss.str();

}


Student Student::fromString(const std::string& str)
{
	Student stu;
	std::stringstream ss(str);
	ss >> stu.m_number >> stu.m_name >> stu.m_grade >> stu.m_math >> stu.m_chinese >> stu.m_english;

	return stu;
}