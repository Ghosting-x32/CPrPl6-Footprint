#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	string letters;
	//cout << "Enter thr letter grouping ('q' to quit): ";
	char ch;
	cout << "�����������ַ���ʼ���ԣ�'q'�����˳���";
	while (cin >> ch && ch != 'q')
	{
		while (cin.get() != '\n')
		{
			continue;
		}

		cout << "Enter thr letter grouping: ";
		cin >> letters;
		cout << "Permutations of " << letters << endl;
		sort(letters.begin(), letters.end());
		cout << letters << endl;
		int temp = 1;
		while (next_permutation(letters.begin(), letters.end()))
		{
			cout << letters << endl;
			temp++;
		}
		cout << "���У� " << temp << " ���������" << endl;
		system("pause");
		system("cls");

		cout << "�����������ַ���ʼ���ԣ�'q'�����˳���";


	}



	system("pause");
	return 0;
}


