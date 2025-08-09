#include<iostream>
#include<fstream>
#include<algorithm>
#include<vector>
#include<string>
#include<cstdlib>
#include"store.h"

using namespace std;

void ShowStr(const string& str);
void GetStrs(ifstream& fin1, vector<string>& vi);

int main()
{
	vector <string> vostr;
	string temp;

	cout << "Enter strings (empty line to quit):\n";
	while (getline(cin, temp) && temp != "\0")
	{
		vostr.push_back(temp);
	}

	for_each(vostr.begin(), vostr.end(), ShowStr);

	ofstream fout("strings.dat", ios_base::out | ios_base::binary);
	for_each(vostr.begin(), vostr.end(), Store(fout));
	fout.close();

	vector<string> vistr;
	ifstream fin("strings.dat", ios_base::in | ios_base::binary);
	if (!fin.is_open())
	{
		cerr << "Could not open file for input.\n";
		exit(EXIT_FAILURE);

	}
	GetStrs(fin, vistr);
	cout << "\nHere are the strings read from the file:\n";
	for_each(vistr.begin(), vistr.end(), ShowStr);








	system("pause");
	return 0;
}

void ShowStr(const string& str)
{
	cout << str << endl;



}


void GetStrs(ifstream& fin1, vector<string>& vi)
{
	size_t len;
	while (fin1.read(reinterpret_cast<char*>(&len), sizeof(size_t)))//先读取字符串的长度，再预分配空间给临时string对象，读取储存字符串
	{
		string str;
		str.resize(len);
		fin1.read(&str[0], len);
		vi.push_back(str);

	}


}