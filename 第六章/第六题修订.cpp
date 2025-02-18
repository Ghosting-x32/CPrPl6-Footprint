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
		cout << "\nGrand Patrons: " << endl;
		int j = 0;
		while (j < jxz)
		{
			if (sjkcc[j].kx > 10000)
			    cout << sjkcc[j].xm << ": " << sjkcc[j].kx << "元." << endl;
			++j;
		}
		cout << "\nPatrons: " << endl;
		int b = 0;
		while (b < jxz) 
		{
		   if (sjkcc[b].kx <= 10000)
				cout << sjkcc[b].xm << ": " << sjkcc[b].kx << "元." << endl;
		   ++b;
		}
	}


	delete[] sjkcc;
	system("pause");
	return 0;
}


