#include<iostream>
#include<string>
#include<map>


using namespace std;



int main()
{
	multimap<int, string> codes;

	//pair<int, string> aaa(415, "San Francisco");
	

	codes.insert(pair<int, string>(415, "San Francisco"));//�����������ڲ�������
	codes.insert(pair<int, string>(510, "Oakland"));
	codes.insert(pair<int, string>(718, "Brooklyn"));
	codes.insert(pair<int, string>(718, "Staten Island"));
	codes.insert(pair<int, string>(415, "San Rafael"));
	codes.insert(pair<int, string>(510, "Berkeley"));

	cout << "Number of cities with area code 415: ";
	cout << codes.count(415) << endl;//ͳ��keyֵΪ415�Ķ����м���
	cout << "Number of cities with area code 718: ";
	cout << codes.count(718) << endl;
	cout << "Number of cities with area code 510: ";
	cout << codes.count(510) << endl;

	cout << "Area Code City\n";
	for (multimap<int, string>::iterator it = codes.begin(); it != codes.end(); it++)
	{
		cout << "\t" << it->first << "\t" << (*it).second << endl;//pair������Ϊ�ṹ��Ĭ�Ϸ���Ȩ��ʱpublic��
		//ֱ�ӷ���pair�ĳ�Ա��������ͨ����Ա�������س�Ա
	}

	pair<multimap<int, string>::iterator,multimap<int, string>::iterator> range = codes.equal_range(718);
	//equal_range()����keyֵ��718�����ж���ĵ��������䣨ָ��ʼ����ĵ�������ָ��ĩβ����ĵ�����������������multimap<int, string>���͵ĵ�����
	cout << "Cities with area code 718:\n";
	for (multimap<int, string>::iterator it = range.first; it != range.second; it++)
	{
		cout << it->second << endl;
	}






	system("pause");
	return 0;
}


