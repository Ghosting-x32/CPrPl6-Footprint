#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iterator>


using namespace std;


int main()
{
	int casts[10] = { 6,7,2,9,4,11,8,7,10,5 };
	vector<int> dice(10);
	copy(casts, casts + 10, dice.begin());
	cout << "Let the dice be cast!\n";
	ostream_iterator<int, char> out_iter(cout, " ");//输出迭代器的一个概念模型
	copy(dice.begin(), dice.end(), out_iter);
	cout << endl;
	cout << "Implicit use of recerse iterator.\n";
	copy(dice.rbegin(), dice.rend(), out_iter);//rbegin()和rend()返回的迭代器类型为reverse_iterator--输出迭代器的一个概念模型
	cout << endl;
	cout << "显示地使用reverse_iterator类型的迭代器：";
	vector<int>::reverse_iterator ri;
	for (ri = dice.rbegin(); ri != dice.rend(); ++ri)
	{
		cout << *ri << " ";

	}
	cout << endl;


	

	system("pause");
	return 0;
}


