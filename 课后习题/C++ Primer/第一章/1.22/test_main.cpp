#include<iostream>
#include<string>
#include"Sales_item.h"

int main()
{
	
	Sales_item total, trans;
	
	std::string index = " ";
	std::cout << "�������������ʼ������\"�˳�\"�����˳�����" << std::endl;
	while (index != "�˳�")
	{
		std::cin >> index;
		std::cout << "�����뼸��ISBN ��ͬ�����ۼ�¼��"
			<< std::endl;
		std::cin.clear();//����Ĵ���cin��ȡʧ�ܣ��Ӷ�����λ��Ԥ������λ����cin������������ȡ


		while (std::cin.get() != '\n')
		{
			continue;
		}


		if (std::cin >> total)
		{
			while (std::cin >> trans)
			{
				if (compareIsbn(total, trans)) // ISBN ��ͬ
				{
					total += trans;
					
				}
				else
				{ // ISBN ��ͬ
					std::cout << "ISBN ��ͬ" << std::endl;
					break;
				}
				
			}
			std::cout << "������Ϣ��ISBN���۳����������۶��ƽ���ۼ�Ϊ "
				<< total << std::endl;

		}
		else
		{
			std::cout << "�㻹û�������κ�����" << std::endl;

		}

		std::cin.clear();//cin����ʧ�ܻ᷵��false��������λ�����ܼ���ʹ��cin���ж�ȡ����Ҫ������ȡ���������λ��ʹ��cin.clear()

		while (std::cin.get() != '\n')
		{
			continue;
		}
		std::cout << "�������������ʼ������\"�˳�\"�����˳�����" << std::endl;
	}
	

	system("pause");
	return 0;
}