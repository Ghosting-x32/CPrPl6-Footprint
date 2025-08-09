#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<cctype>
#include<iterator>


using namespace std;

string& ToLower(string& st);
void display(const string& s);



int main()
{
	/*string q1 = "QUEled36d";//��������ȫ�ֺ�����û������
	display(q1);
	string q2;
	q2 = ToLower(q1);
	display(q2);*/

	vector<string> words;
	string input;
	cout << "Enter words (enter \"q**\" to quit): \n";

	while (cin >> input && input != "q**")
	{
		words.push_back(input);
	}

	cout << "You entered the following words:\n";
	for_each(words.begin(), words.end(), display);
	cout << endl;

	set<string> wordset;
	//��vectorʸ�������ڵ�Ԫ�ز��뵽set����������
	transform(words.begin(), words.end(), insert_iterator<set<string>>(wordset, wordset.begin()), ToLower);
	cout << "\nAlphabetic list of words:\n";
	for_each(wordset.begin(), wordset.end(), display);
	cout << endl;

	map<string, int> wordmap;
	set<string>::iterator si;
	for (si = wordset.begin(); si != wordset.end(); si++)
	{
		wordmap[*si] = count(words.begin(), words.end(), *si);//����佫����ֵ���Զ����뵽mapӳ��������
		//��Ч����������
		//wordmap.insert(pair<string, int>(*si, count(words.begin(), words.end(), *si)));


	}

	cout << "\nWord frequency:\n";
	for (si = wordset.begin(); si != wordset.end(); si++)
	{
		cout << *si << ": " << wordmap[*si] << endl;
	}



	system("pause");
	return 0;
}



string& ToLower(string& st)
{
	transform(st.begin(), st.end(), st.begin(), tolower);
	return st;


}


void display(const string& s)
{

	cout << s << " ";
}

