#include <iostream>
#include<string>

#include"Cpmv.h"

using namespace std;


int main()
{
	{
		Cpmv cpmv1;
		cpmv1.Display();
		Cpmv cpmv2("����", "�ٺ�");
		cpmv2.Display();
		Cpmv cpmv3(cpmv2);
		cpmv3.Display();
		Cpmv cpmv4(cpmv2 + cpmv3);//����RVO������ֵ�Ż������������ƶ����캯��
		cpmv4.Display();

		cpmv1 = cpmv2;
		cpmv1.Display();

		cpmv1 = cpmv2 + cpmv4;
		cpmv1.Display();
	}








	system("pause");
	return 0;
}


