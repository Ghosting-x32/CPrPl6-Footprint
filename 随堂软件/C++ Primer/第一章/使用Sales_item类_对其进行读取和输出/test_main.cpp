#include<iostream>
#include<string>
#include"Sales_item.h"

int main()
{
	std::string v1 = "ggggg";
//����5�����캯��
	//1.Ĭ�Ϲ��캯��
	Sales_item book;
	//2.����һ��istream���������βεĹ��캯��
	//Sales_item book1(std::cin);
	//3.����һ��char*�����βεĹ��캯����char*�Զ�ת��Ϊstring��
	Sales_item book3("hhhh");//-----��������ͬһ�����캯��
	//3..����һ��string���������βεĹ��캯��
	Sales_item book4(v1);//-------��������ͬһ�����캯��
//��λ��г����Զ��ṩ��4.���ƹ��캯����5.�ƶ����캯��
	//std::cin >> book;
	//std::cout << book << std::endl;
	//std::cout << book1 << std::endl;
	std::cout << book3 << std::endl;
	std::cout << book4 << std::endl;



	system("pause");
	return 0;
}