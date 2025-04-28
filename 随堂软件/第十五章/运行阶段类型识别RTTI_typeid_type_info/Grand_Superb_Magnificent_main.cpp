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
		cout << "Now processing type " << typeid(*pg).name() << ".\n";//typeid(*pg)����һ��type_info���������ã�type_info����һ����Ա����name
		//type_info��ͷ�ļ�<typeinfo>
		pg->Speak();
		//���н׶�����ʶ��RTTI
		//���ʽ��ֵΪ��ֵ�����psΪnullptr,��ñ��ʽps = dynamic_cast<Superb*>(pg)��ֵΪ0����if���ж�����Ϊfalse
		//���ps��Ϊnullptr,��ñ��ʽps = dynamic_cast<Superb*>(pg)��ֵ��Ϊ0������������ֵ����if���ж�����Ϊtrue
		/*
		ps = dynamic_cast<Superb*>(pg)
		if (ps != nullptr)
		{
			ps->Say();
		}
		
		�����õ�Ч������
		*/
		if (ps = dynamic_cast<Superb*>(pg))//pg����ܸ�ֵ��ps��Superb*���͵�ָ�룩,��ps = pg,����ps = nullptr
		{
			ps->Say();
		}

		if (typeid(Magnificent) == typeid(*pg))//���pg��ָ��Magnificent���ʽ����true�����򷵻�false
		{
			cout << "Yes, you're really magnificent.\n";


		}

		delete pg;
		/*if (ps != nullptr)
		{//����ظ��ͷ��ڴ�
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

	//******�ص�****
	Grand* p = nullptr;//***ָ��Ҫ��ʼ�������ظ�ָ��Ų��ᱨ��

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
	//������default
	//��Ȼ�߼��� dis(gen) % 3 �Ľ��ֻ���� 0��1 �� 2�����������޷���̬�ƶϳ���һ�㣬���������Ϊ default ��֧���ܱ�ִ�С�
	//��� default ��֧��ִ�У�ָ�� p ��δ����ʼ��������δ������Ϊ���緵��Ұָ�룩��
	}

	return p;
}