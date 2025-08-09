#include<iostream>
#include<string>
#include<memory>

#include"Report.h"

using namespace std;



int main()
{
	//{
	//	auto_ptr<Report>ps(new Report("using auto_ptr"));//c++17标准已经将auto_ptr智能指针移除
	//	ps->comment();
	//}
	{
		shared_ptr<Report>ps(new Report("using shared_ptr"));
		ps->comment();
	}

	{
		unique_ptr<Report>ps(new Report("using unique_ptr"));
		ps->comment();


	}



	system("pause");
	return 0;
}