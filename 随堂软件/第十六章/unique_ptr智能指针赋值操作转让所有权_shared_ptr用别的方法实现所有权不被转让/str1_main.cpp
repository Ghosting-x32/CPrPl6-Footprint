#include<iostream>
#include<string>
#include<memory>



using namespace std;

void text1();
void text2();

int main()
{
	text1();
	cout << "=================================" << endl;
	text2();



	system("pause");
	return 0;
}

void text1()
{
	unique_ptr<string> films[5] =
	{
		unique_ptr<string>(new string("Fowl Balls")),
		unique_ptr<string>(new string("Duck Walks")),
		unique_ptr<string>(new string("Chicken Runs")),
		unique_ptr<string>(new string("Turkey Errors")),
		unique_ptr<string> (new string("Coose Eggs")),

	};

	//unique_ptr<string> pwin;
	//pwin = films[2];//��ֵ����ת������Ȩ��unique_ptr�����������������³����޷�����
	//�ϰ�auto_ptr������������������films[2]����Ȩת�ø�pwin������films[2]���ܷ���Chicken Runs�ַ���
	//���films[2]ʱ���ֲ�ȷ������

	cout << "The nominees for best avian baseball film are\n";
	for (int i = 0; i < 5; i++)
	{

		cout << *films[i] << endl;
	}

	//cout << "The winner is " << *pwin << "!\n";



}


void text2()
{
	shared_ptr<string> films[5] =
	{
		shared_ptr<string>(new string("Fowl Balls")),
		shared_ptr<string>(new string("Duck Walks")),
		shared_ptr<string>(new string("Chicken Runs")),
		shared_ptr<string>(new string("Turkey Errors")),
		shared_ptr<string>(new string("Coose Eggs")),

	};

	shared_ptr<string> pwin;//shared_ptr���������Ȩת������
	pwin = films[2];

	cout << "The nominees for best avian baseball film are\n";
	for (int i = 0; i < 5; i++)
	{

		cout << *films[i] << endl;
	}

	cout << "The winner is " << *pwin << "!\n";


}