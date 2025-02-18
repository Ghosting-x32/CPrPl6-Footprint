#include<iostream>
#include<string>
#include<fstream>
using namespace std;
struct sjk
{
	string xm;
	double kx;
};

int main()
{
	ifstream inFile;
	inFile.open("carinfo.txt");
	int jxz;
	cout << "请输入捐献者的数目：";
	inFile >> jxz;
	inFile.get();
	cout << jxz << endl;
	int k = 0;
	sjk* sjkcc = new sjk[jxz];
	for (int i = 0; i < jxz; i++)
	{
		cout << "请输入第" << i + 1 << "位捐献者的名字：";
		getline(inFile, sjkcc[i].xm);
		cout << sjkcc[i].xm << endl;
		cout << "请输入第" << i + 1 << "位捐献者的款项：";
		inFile >> sjkcc[i].kx;
		inFile.get();
		cout << sjkcc[i].kx << endl;
		if (sjkcc[i].kx > 10000)
			++k;
	}
	
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


