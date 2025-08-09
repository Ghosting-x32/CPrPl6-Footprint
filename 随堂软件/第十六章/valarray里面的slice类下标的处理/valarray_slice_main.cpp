#include<iostream>
#include<string>
#include<valarray>
#include<random>

using namespace std;

const int SIZE = 12;

void show(const valarray<int>& v, int cols);

int main()
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dis(0, 9);

	valarray<int> valint(SIZE);

	int i;
	for (i = 0; i < SIZE; i++)
	{
		valint[i] = dis(gen);
	}
	cout << "Original array:\n";
	show(valint, 3);

	valarray<int> vcol(valint[slice(1, 4, 3)]);//2 5 8 11
	//slice(起始索引，索引数，跨距)
	cout << "Second column:\n";
	show(vcol, 1);

	valarray<int> vrow(valint[slice(3, 3, 1)]);//4 5 6
	cout << "Second row:\n";
	show(vrow, 3);

	valint[slice(2, 4, 3)] = 10;//3 6 9 12
	cout << "Set last columnto 10:\n";
	show(valint, 3);

	cout << "Set first column to sum of next two:\n";
	valint[slice(0, 4, 3)] = valarray<int>(valint[slice(1, 4, 3)]) + valarray<int>(valint[slice(2, 4, 3)]);
	//1 4 7 10                                        2 5 8 11                              3 6 9 12
	show(valint, 3);









	system("pause");
	return 0;
}



void show(const valarray<int>& v, int cols)
{
	int lim = v.size();
	for (int i = 0; i < lim; i++)
	{
		cout.width(3);
		cout << v[i];
		if (i % cols == cols - 1)
		{
			cout << endl;
		}
		else
		{
			cout << " ";
		}

	}
	if (lim % cols != 0)
	{
		cout << endl;
	}

}

