#include<iostream>
#include<string>
#include<map>


using namespace std;



int main()
{
	multimap<int, string> codes;

	//pair<int, string> aaa(415, "San Francisco");
	

	codes.insert(pair<int, string>(415, "San Francisco"));//匿名对组用于插入容器
	codes.insert(pair<int, string>(510, "Oakland"));
	codes.insert(pair<int, string>(718, "Brooklyn"));
	codes.insert(pair<int, string>(718, "Staten Island"));
	codes.insert(pair<int, string>(415, "San Rafael"));
	codes.insert(pair<int, string>(510, "Berkeley"));

	cout << "Number of cities with area code 415: ";
	cout << codes.count(415) << endl;//统计key值为415的对组有几个
	cout << "Number of cities with area code 718: ";
	cout << codes.count(718) << endl;
	cout << "Number of cities with area code 510: ";
	cout << codes.count(510) << endl;

	cout << "Area Code City\n";
	for (multimap<int, string>::iterator it = codes.begin(); it != codes.end(); it++)
	{
		cout << "\t" << it->first << "\t" << (*it).second << endl;//pair被定义为结构（默认访问权限时public）
		//直接访问pair的成员，而不是通过成员函数返回成员
	}

	pair<multimap<int, string>::iterator,multimap<int, string>::iterator> range = codes.equal_range(718);
	//equal_range()返回key值是718的所有对组的迭代器区间（指向开始对组的迭代器，指向末尾对组的迭代器），返回两个multimap<int, string>类型的迭代器
	cout << "Cities with area code 718:\n";
	for (multimap<int, string>::iterator it = range.first; it != range.second; it++)
	{
		cout << it->second << endl;
	}






	system("pause");
	return 0;
}


