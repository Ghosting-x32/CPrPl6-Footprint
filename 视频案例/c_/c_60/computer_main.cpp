#include<iostream>
#include<string>
#include"Computer.h"
#include"CPU.h"
#include"IntelCPU.h"
#include"IntelMemory.h"
#include"IntelVideoCard.h"
#include"LenovoCPU.h"
#include"LenovoMemory.h"
#include"LenovoVideoCard.h"
#include"Memory.h"
#include"VideoCard.h"


using namespace std;
void test01();




int main()
{
	test01();


	system("pause");
	return 0;
}



void test01()
{
	//第一台电脑零件
	CPU* intelcpu1 = new IntelCPU;
	VideoCard* intelvc1 = new IntelVideoCard;
	Memory* intelmem1 = new IntelMemory;

	//第一台电脑运行
	/*Computer computer1(intelcpu1, intelvc1, intelmem1);
	computer1.work();
	*/
	Computer* computer1 = new Computer(intelcpu1, intelvc1, intelmem1);
	computer1->work();
	delete computer1;

	cout << "------------------------------------------------" << endl;
	//第二台电脑运行
	Computer* computer2 = new Computer(new LenovoCPU, new LenovoVideoCard, new LenovoMemory);
	computer2->work();
	delete computer2;

	cout << "------------------------------------------------" << endl;
	//第三台电脑运行
	Computer* computer3 = new Computer(new IntelCPU, new LenovoVideoCard, new LenovoMemory);
	computer3->work();
	delete computer3;
}


