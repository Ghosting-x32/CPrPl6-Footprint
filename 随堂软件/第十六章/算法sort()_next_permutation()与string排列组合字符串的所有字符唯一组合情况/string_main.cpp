#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	string letters;
	//cout << "Enter thr letter grouping ('q' to quit): ";
	char ch;
	cout << "请输入任意字符开始测试，'q'代表退出！";
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
		cout << "共有： " << temp << " 种排列组合" << endl;
		system("pause");
		system("cls");

		cout << "请输入任意字符开始测试，'q'代表退出！";


	}



	system("pause");
	return 0;
}


