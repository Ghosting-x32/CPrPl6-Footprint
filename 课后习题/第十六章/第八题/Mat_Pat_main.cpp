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

	cout << "请Mat输入你的朋友的名字：(\"q**\"代表输入结束)" << endl;
	while (getline(cin, temp) && temp != "q**")
	{
		Mat.insert(temp);
		cout << "请Mat输入你的下一个朋友的名字：(\"q**\"代表输入结束)" << endl;
	}

	cout << "Mat的所有朋友名字分别为：" << endl;
	for_each(Mat.begin(), Mat.end(), show);
	cout << endl;



	cout << "请Pat输入你的朋友的名字：(\"q**\"代表输入结束)" << endl;
	while (getline(cin, temp1) && temp1 != "q**")
	{
		Pat.insert(temp1);
		cout << "请Pat输入你的下一个朋友的名字：(\"q**\"代表输入结束)" << endl;
	}

	cout << "Pat的所有朋友名字分别为：" << endl;
	for_each(Pat.begin(), Pat.end(), show);
	cout << endl;

	set_union(Mat.begin(), Mat.end(), Pat.begin(), Pat.end(), insert_iterator<set<string>>(Mat_Pat, Mat_Pat.begin()));
	//集合算合集并插到第三个集合中

	cout << "Mat和Pat的所有朋友名字分别为：" << endl;
	for_each(Mat_Pat.begin(), Mat_Pat.end(), show);
	cout << endl;






	system("pause");
	return 0;
}



void show(const string& st)
{

	cout << st << ", ";
}