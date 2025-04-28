#include<iostream>
#include<string>
#include<random>
#include<typeinfo>


#include"Grand.h"
#include"Magnificent.h"
#include"Superb.h"

using namespace std;

Grand* GetOne();


int main()
{
	Grand* pg;
	Superb* ps;
	for (int i = 0; i < 5; i++)
	{
		pg = GetOne();
		cout << "Now processing type " << typeid(*pg).name() << ".\n";//typeid(*pg)返回一个type_info类对象的引用，type_info类有一个成员函数name
		//type_info在头文件<typeinfo>
		pg->Speak();
		//运行阶段类型识别RTTI
		//表达式的值为左值，如果ps为nullptr,则该表达式ps = dynamic_cast<Superb*>(pg)的值为0，即if的判断条件为false
		//如果ps不为nullptr,则该表达式ps = dynamic_cast<Superb*>(pg)的值不为0，可以是任意值，即if的判断条件为true
		/*
		ps = dynamic_cast<Superb*>(pg)
		if (ps != nullptr)
		{
			ps->Say();
		}
		
		其作用等效于这样
		*/
		if (ps = dynamic_cast<Superb*>(pg))//pg如果能赋值给ps（Superb*类型的指针）,则ps = pg,否则ps = nullptr
		{
			ps->Say();
		}

		if (typeid(Magnificent) == typeid(*pg))//如果pg是指向Magnificent表达式返回true，否则返回false
		{
			cout << "Yes, you're really magnificent.\n";


		}

		delete pg;
		/*if (ps != nullptr)
		{//造成重复释放内存
			delete ps;
		}*/
		

	}






	system("pause");
	return 0;
}


Grand* GetOne()
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dis(0, 10000);

	//******重点****
	Grand* p = nullptr;//***指针要初始化，返回该指针才不会报错

	switch (dis(gen) % 3)
	{
	case 0:
	{
		p = new Grand(dis(gen) % 100);
	}
	break;
	case 1:
	{
		p = new Superb(dis(gen) % 100);
	}
	break;
	case 2:
	{
		p = new Magnificent(dis(gen) % 100, 'A' + dis(gen) % 26);
	}
	break;
	default:
		break;
	//不能有default
	//虽然逻辑上 dis(gen) % 3 的结果只能是 0、1 或 2，但编译器无法静态推断出这一点，因此它会认为 default 分支可能被执行。
	//如果 default 分支被执行，指针 p 将未被初始化，导致未定义行为（如返回野指针）。
	}

	return p;
}