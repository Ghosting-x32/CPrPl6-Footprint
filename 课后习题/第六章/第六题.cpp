#include<iostream>
#include<string>
using namespace std;
struct sjk
{
	string xm;
	double kx;
};

int main()
{
	int jxz;
	cout << "请输入捐献者的数目：";
	cin >> jxz;
	cin.get();
	sjk* sjkcc = new sjk[jxz];
	for (int i = 0; i < jxz; i++)
	{
		cout << "请输入第" << i + 1 << "位捐献者的名字：";
		getline(cin, sjkcc[i].xm);
		cout << "请输入第" << i + 1 << "位捐献者的款项：";
		cin >> sjkcc[i].kx;
		cin.get();
	}

	int k = 0;
	while (sjkcc[k].kx > 10000)
		++k;

	if (k == jxz)
	{
		cout << "\nGrand Patrons: " << endl;
		int j = 0;
		while (j < jxz)
		{
			cout << sjkcc[j].xm << ": " << sjkcc[j].kx << "元." << endl;
			++j;
		}
		cout << "\nPatrons: \n" << "None!\n";
	}
	else if (k == 0)
	{
		cout << "\nPatrons: " << endl;
		int j = 0;
		while (j < jxz)
		{
			cout << sjkcc[j].xm << ": " << sjkcc[j].kx << "元." << endl;
			++j;
		}
		cout << "\nGrand Patrons: \n" << "None!\n";
	}
	else
	{
		int j = 0;
		if (sjkcc[j].kx > 10000)
		{
			cout << "\nGrand Patrons: " << endl;
			while (j < jxz)
			{
				cout << sjkcc[j].xm << ": " << sjkcc[j].kx << "元." << endl;
				++j;
			}
		}
		else
		{
			cout << "\nPatrons: " << endl;
			while (j < jxz)
			{
				cout << sjkcc[j].xm << ": " << sjkcc[j].kx << "元." << endl;
				++j;
			}
		}
	}


	delete[] sjkcc;
	system("pause");
	return 0;
}


