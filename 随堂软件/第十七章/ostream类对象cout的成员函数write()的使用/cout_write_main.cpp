#include<iostream>
#include<string>
#include<cstring>

using namespace std;

int main()
{
	const char* state1 = "Florida";
	const char* state2 = "Kansas";
	const char* state3 = "Euphoria";
	int len = strlen(state2);
	cout << "Increasing loop index:\n";
	int i;
	for (i = 1; i <= len; i++)
	{
		cout.write(state2, i);//warite(ָ���ַ�����ָ�루��ַ���� ��ʾ�ַ�������Ŀ)
		cout << endl;

	}

	cout << "Decreasing loop index:\n";
	for (i = len; i > 0; i--)
	{
		cout.write(state2, i) << endl;//write()����cout&�������������

	}

	cout << "Exceeding string length:\n";
	cout.write(state2, len + 5) << endl;//������state2,write���ڼ������state2�����ڴ��е�δ֪����

	cout << "Exceeding string length:\n";
	cout.write(state2, len - 7) << endl;//������state2,write���ڼ������state2ǰ���ڴ��е�δ֪����



	system("pause");
	return 0;
}