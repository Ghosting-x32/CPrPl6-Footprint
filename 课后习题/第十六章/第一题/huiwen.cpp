#include<iostream>
#include<string>

using namespace std;

bool huiwen(string& te);

int main()
{
	string text1;
	cout << "��������Ҫ���Ե��ַ�����" << endl;
	cin >> text1;

	if (huiwen(text1))
	{
		cout << "���ַ����ǻ��ģ�" << endl;
	}
	else
	{
		cout << "���ַ��������ǻ��ģ�����" << endl;
	}





	system("pause");
	return 0;
}



bool huiwen(string& te)
{
	string temp;
	
	auto it = temp.begin();
	for (auto i = te.rbegin(); i != te.rend(); i++, it++)
	{
		//iterator insert(const_iterator p, charT c);
		temp.insert(it, *i);
	}

	if (temp == te)
	{
		cout << "---" << temp << "---" << endl;
		return true;
	}
	else
	{
		cout << "---" << temp << "---" << endl;
		return false;
	}
}