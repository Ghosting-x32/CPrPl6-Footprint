#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<iterator>

using namespace std;

void show(const string& st);

int main()
{
	set<string> Mat;
	set<string> Pat;
	set<string> Mat_Pat;
	string temp;
	string temp1;

	cout << "��Mat����������ѵ����֣�(\"q**\"�����������)" << endl;
	while (getline(cin, temp) && temp != "q**")
	{
		Mat.insert(temp);
		cout << "��Mat���������һ�����ѵ����֣�(\"q**\"�����������)" << endl;
	}

	cout << "Mat�������������ֱַ�Ϊ��" << endl;
	for_each(Mat.begin(), Mat.end(), show);
	cout << endl;



	cout << "��Pat����������ѵ����֣�(\"q**\"�����������)" << endl;
	while (getline(cin, temp1) && temp1 != "q**")
	{
		Pat.insert(temp1);
		cout << "��Pat���������һ�����ѵ����֣�(\"q**\"�����������)" << endl;
	}

	cout << "Pat�������������ֱַ�Ϊ��" << endl;
	for_each(Pat.begin(), Pat.end(), show);
	cout << endl;

	set_union(Mat.begin(), Mat.end(), Pat.begin(), Pat.end(), insert_iterator<set<string>>(Mat_Pat, Mat_Pat.begin()));
	//������ϼ����嵽������������

	cout << "Mat��Pat�������������ֱַ�Ϊ��" << endl;
	for_each(Mat_Pat.begin(), Mat_Pat.end(), show);
	cout << endl;






	system("pause");
	return 0;
}



void show(const string& st)
{

	cout << st << ", ";
}