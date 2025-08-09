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
	//	cout << "标点符号：" << ch << endl;
	//}
	//else
	//{
	//	cout << "cuocuocuo" << endl;
	//}

	string text1;
	cout << "请输入你要测试的字符串：" << endl;
	//cin >> text1;
	getline(cin, text1);

	if (huiwen(text1))
	{
		cout << "该字符串是回文！" << endl;
	}
	else
	{
		cout << "该字符串不是是回文！！！" << endl;
	}





	system("pause");
	return 0;
}



bool huiwen(string& te)
{
	//方法一：
	/*string temp;
	string temp2;
	temp2.resize(1);
	int k = 0;
	int f = 2;
	for (int j = 0; j < te.size(); j++)
	{

		//是标点符号返回true       是空白返回true
		if ((!ispunct(te[j])) && (!isspace(te[j])))
		{
			//如果是大写返回其小写，否则返回其自身
			temp2[k] = tolower(te[j]);
			temp2.resize(f++);//每次增加一个字符后扩充一个位置--手动管理内存
			k++;
		}
	}
	temp2.pop_back();//删除最后一个扩充的位置
	cout << "去除标点符号和空白以及大写转小写之后：" << temp2 << endl;

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



	//方法二：---预分配的空间不足时，会重新寻找更大的空间，导致原来的迭代器无法使用
	//需要重新获取迭代器?或者reserve()预分配大小（当内存.size()大于预分配时才重新寻找更大的空间）
	string temp3;
	temp3.reserve(100);
	auto it3 = temp3.begin();
	for (auto it1 = te.begin(); it1 != te.end(); it1++)
	{
		//cout << "---" << *it1 << "---" << endl;
		//是标点符号返回true       是空白返回true
		if ((!ispunct(*it1)) && (!isspace(*it1)))
		{
			//如果是大写返回其小写，否则返回其自身
			temp3.insert(it3, tolower(*it1));			
			it3++;
		}
	}

	cout << "去除标点符号和空白以及大写转小写之后的字符串：---" << temp3 << "---" << endl;
	cout << "每个字符展示: ";
	for_each(temp3.begin(), temp3.end(), show);
	cout << endl;

	string temp1;//该方法不需要手动管理内存
	temp1.reserve(100);
	auto it2 = temp1.begin();
	for (auto it1 = te.rbegin(); it1 != te.rend(); it1++)
	{
		//cout << "---" << *it1 << "---" << endl;
		//是标点符号返回true       是空白返回true
		if ((!ispunct(*it1)) && (!isspace(*it1)))//可以直接用第一题的for循环对temp3进行操作而不必再判断
		{
			//如果是大写返回其小写，否则返回其自身
			temp1.insert(it2, tolower(*it1));
			it2++;
		}
	}

	if (temp1 == temp3)
	{
		cout << "去除标点符号和空白以及大写转小写反转之后大小：" << temp1.size() << endl;
		cout << "去除标点符号和空白以及大写转小写之后大小：" << temp3.size() << endl;
		cout << "反转之后的字符串---" << temp1 << "---" << endl;
		cout << "每个字符展示: ";
		for_each(temp1.begin(), temp1.end(), show);
		cout << endl;
		return true;
	}
	else
	{
		cout << "去除标点符号和空白以及大写转小写反转之后大小：" << temp1.size() << endl;
		cout << "去除标点符号和空白以及大写转小写之后大小：" << temp3.size() << endl;
		cout << "反转之后的字符串---" << temp1 << "---" << endl;
		cout << "每个字符展示: ";
		for_each(temp1.begin(), temp1.end(), show);
		cout << endl;
		return false;
	}
}


void show(const char& st)
{
	cout << st << "-";
}