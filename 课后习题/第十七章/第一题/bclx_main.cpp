#include<iostream>





using namespace std;



int main()
{
	int num1 = 0;
	char ch;
	cout << "������һЩ�ַ���" << endl;
	while (cin.get(ch) && ch != '$')
	{
		num1++;
		cout << ch;
	}
	cout << "\n$֮ǰ���ַ����ǣ�" << num1 << endl;

	cin.putback(ch);
	char ch1;
	cin.get(ch1);
	cout << "����������һ���ַ��ǣ�" << ch1 << endl;
	cout << "������ַ��ǣ�" << endl;
	while (cin.get(ch1))//����ģ���ļ�β����ѭ����ctrl+Z��
	{

		cout << ch1;
	}

	system("pause");
	return 0;
}