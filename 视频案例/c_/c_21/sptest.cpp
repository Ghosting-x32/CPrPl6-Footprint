#include "sptest.h"

void Cube::setL(int l)
{
	m_L = l;
}

int Cube::getL()
{
	return m_L;
}

void Cube::setW(int w)
{
	m_W = w;
}

int Cube::getW()
{
	return m_W;
}

void Cube::setH(int h)
{
	m_H = h;
}

int Cube::getH()
{
	return m_H;
}

int Cube::calculateS()
{
	return (2 * m_L * m_W + 2 * m_L * m_H + 2 * m_W * m_H);
}

int Cube::calculateV()
{
	return (m_L * m_W * m_H);
}

bool Cube::isSameByClass(Cube& c)
{
	if (m_L == c.getL() && m_W == c.getW() && m_H == c.getH())
	{
		return true;
	}
	else
	{
		return false;
	}
}