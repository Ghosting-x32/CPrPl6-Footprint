#include<iostream>
#include<string>


using namespace std;

int main()
{
	float price1 = 20.40;
	float price2 = 1.9 + 8.0 / 9.0;

	cout.setf(ios_base::showpoint);//��ʾС���㣬���ֺ����0�ᱻ��ʾ
	cout << "\"Furry Friends\" is $" << price1 << "!\n";
	cout << "\"Fiery Fiends\" is $" << price2 << "!\n";

	cout.precision(2);//Ĭ��״̬����������λ��
	cout << "\"Furry Friends\" is $" << price1 << "!\n";
	cout << "\"Fiery Fiends\" is $" << price2 << "!\n";











	system("pause");
	return 0;
}