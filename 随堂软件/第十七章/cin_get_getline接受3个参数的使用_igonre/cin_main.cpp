#include<iostream>

const int Limit = 225;

using namespace std;

int main()
{
	char input[Limit];

	cout << "Enter a string for getline() processing:\n";
	cin.getline(input, Limit, '#');//(char*, �����Ŀ�ַ�, �ֽ��)----���������Ŀ�ַ�ֹͣ��ȡ������ֽ��ֹͣ��ȡ���ֽ�����������б�����
	cout << "Herr is your input: \n";
	cout << input << "\nDone with phase 1\n";

	char ch;
	cin.get(ch);
	cout << "The next input character ia " << ch << endl;

	if (ch != '\n')
	{
		cin.ignore(Limit, '\n');//������������Limit���ַ������߶���������'\n'֮ǰ�������ַ�


	}

	cout << "Enter a string for get() processing:\n";
	cin.get(input, Limit, '#');//(char*, �����Ŀ�ַ�, �ֽ��)----���������Ŀ�ַ�ֹͣ��ȡ������ֽ��ֹͣ��ȡ���ֽ��������������
	cout << "Here is your input:\n";
	cout << input << "\nDone with phase 2\n";

	cin.get(ch);
	cout << "The nex input character is " << ch << endl;




	system("pause");
	return 0;
}