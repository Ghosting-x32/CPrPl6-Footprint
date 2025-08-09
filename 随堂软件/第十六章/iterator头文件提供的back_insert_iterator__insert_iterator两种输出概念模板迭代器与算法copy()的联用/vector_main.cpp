#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iterator>


using namespace std;

void output(const string& s);

int main()
{
	string s1[4] = { "fine", "fish", "fashion", "fate" };
	string s2[2] = { "busy", "bats" };
	string s3[2] = { "silly", "singers" };

	vector<string> words(4);
	copy(s1, s1 + 4, words.begin());
	for_each(words.begin(), words.end(), output);
	cout << endl;

	//β��
	copy(s2, s2 + 2, back_insert_iterator<vector<string>>(words));//������back_insert_iterator���͵�����---������������͸���ģ��
	for_each(words.begin(), words.end(), output);
	cout << endl;


	//words.begin()������ͷ�壬���Ըı�������λ�ò�
	copy(s3, s3 + 2, insert_iterator<vector<string>>(words, words.begin()));//������insert_iterator���͵�����---������������͸���ģ��
	for_each(words.begin(), words.end(), output);
	cout << endl;



	

	system("pause");
	return 0;
}


void output(const string& s)
{
	cout << s << " ";

}