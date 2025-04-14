#ifndef COMPUTER_H_
#define COMPUTER_H_
#include<iostream>
#include<string>
#include"CPU.h"
#include"VideoCard.h"
#include"Memory.h"
using namespace std;


class Computer
{
public:
	Computer(CPU* cpu, VideoCard* vc, Memory* mem);
	~Computer();
	void work();

	
private:
	CPU* m_cpu;
	VideoCard* m_vc;
	Memory* m_mem;
};







#endif