#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

bool huiwen(string& te);
void show(const char& st);

int main()
{
	//char ch;
	//cin >> ch;
	//if (!ispunct(ch))
	//{
	//	cout << "�����ţ�" << ch << endl;
	//}
	//else
	//{
	//	cout << "cuocuocuo" << endl;
	//}

	string text1;
	cout << "��������Ҫ���Ե��ַ�����" << endl;
	//cin >> text1;
	getline(cin, text1);

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
	//����һ��
	/*string temp;
	string temp2;
	temp2.resize(1);
	int k = 0;
	int f = 2;
	for (int j = 0; j < te.size(); j++)
	{

		//�Ǳ����ŷ���true       �ǿհ׷���true
		if ((!ispunct(te[j])) && (!isspace(te[j])))
		{
			//����Ǵ�д������Сд�����򷵻�������
			temp2[k] = tolower(te[j]);
			temp2.resize(f++);//ÿ������һ���ַ�������һ��λ��--�ֶ������ڴ�
			k++;
		}
	}
	temp2.pop_back();//ɾ�����һ�������λ��
	cout << "ȥ�������źͿհ��Լ���дתСд֮��" << temp2 << endl;

	for_each(temp2.begin(), temp2.end(), show);
	cout << endl;
	//temp2.pop_back();
	//for_each(temp2.begin(), temp2.end(), show);
	//cout << endl;



	auto it = temp.begin();
	for (auto i = temp2.rbegin(); i != temp2.rend(); i++, it++)
	{
		//iterator insert(const_iterator p, charT c);
		temp.insert(it, *i);
	}

	if (temp == temp2)
	{
		cout << temp.size() << " , " << temp2.size() << endl;
		cout << "---" << temp << "---" << endl;
		for_each(temp.begin(), temp.end(), show);
		cout << endl;
		return true;
	}
	else
	{
		cout << temp.size() << " , " << temp2.size() << endl;
		cout << "---" << temp << "---" << endl;
		for_each(temp.begin(), temp.end(), show);
		cout << endl;
		return false;
	}*/



	//��������---Ԥ����Ŀռ䲻��ʱ��������Ѱ�Ҹ���Ŀռ䣬����ԭ���ĵ������޷�ʹ��
	//��Ҫ���»�ȡ������?����reserve()Ԥ�����С�����ڴ�.size()����Ԥ����ʱ������Ѱ�Ҹ���Ŀռ䣩
	string temp3;
	temp3.reserve(100);
	auto it3 = temp3.begin();
	for (auto it1 = te.begin(); it1 != te.end(); it1++)
	{
		//cout << "---" << *it1 << "---" << endl;
		//�Ǳ����ŷ���true       �ǿհ׷���true
		if ((!ispunct(*it1)) && (!isspace(*it1)))
		{
			//����Ǵ�д������Сд�����򷵻�������
			temp3.insert(it3, tolower(*it1));			
			it3++;
		}
	}

	cout << "ȥ�������źͿհ��Լ���дתСд֮����ַ�����---" << temp3 << "---" << endl;
	cout << "ÿ���ַ�չʾ: ";
	for_each(temp3.begin(), temp3.end(), show);
	cout << endl;

	string temp1;//�÷�������Ҫ�ֶ������ڴ�
	temp1.reserve(100);
	auto it2 = temp1.begin();
	for (auto it1 = te.rbegin(); it1 != te.rend(); it1++)
	{
		//cout << "---" << *it1 << "---" << endl;
		//�Ǳ����ŷ���true       �ǿհ׷���true
		if ((!ispunct(*it1)) && (!isspace(*it1)))//����ֱ���õ�һ���forѭ����temp3���в������������ж�
		{
			//����Ǵ�д������Сд�����򷵻�������
			temp1.insert(it2, tolower(*it1));
			it2++;
		}
	}

	if (temp1 == temp3)
	{
		cout << "ȥ�������źͿհ��Լ���дתСд��ת֮���С��" << temp1.size() << endl;
		cout << "ȥ�������źͿհ��Լ���дתСд֮���С��" << temp3.size() << endl;
		cout << "��ת֮����ַ���---" << temp1 << "---" << endl;
		cout << "ÿ���ַ�չʾ: ";
		for_each(temp1.begin(), temp1.end(), show);
		cout << endl;
		return true;
	}
	else
	{
		cout << "ȥ�������źͿհ��Լ���дתСд��ת֮���С��" << temp1.size() << endl;
		cout << "ȥ�������źͿհ��Լ���дתСд֮���С��" << temp3.size() << endl;
		cout << "��ת֮����ַ���---" << temp1 << "---" << endl;
		cout << "ÿ���ַ�չʾ: ";
		for_each(temp1.begin(), temp1.end(), show);
		cout << endl;
		return false;
	}
}


void show(const char& st)
{
	cout << st << "-";
}