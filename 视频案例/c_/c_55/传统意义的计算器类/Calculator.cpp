#include"Calculator.h"

int Calculator::getResult(string oper)
{
	if (oper == "+")
	{
		return m_Num1 + m_Num2;
	}
	else if (oper == "-")
	{
		return m_Num1 - m_Num2;
	}
	else if(oper == "*")
	{
		return m_Num1 * m_Num2;
	}
}

