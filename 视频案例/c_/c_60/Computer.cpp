#include"Computer.h"

Computer::Computer(CPU* cpu, VideoCard* vc, Memory* mem)
{
	m_cpu = cpu;
	m_vc = vc;
	m_mem = mem;
}

Computer::~Computer()
{
	if (m_cpu != NULL)
	{
		delete m_cpu;
		m_cpu = NULL;
	}

	if (m_vc != NULL)
	{
		delete m_vc;
		m_vc = NULL;
	}

	if (m_mem != NULL)
	{
		delete m_mem;
		m_mem = NULL;
	}
}

void Computer::work()
{
	m_cpu->calculate();
	m_vc->display();
	m_mem->storage();
}