#include<iostream>
#include<fstream>
#include<cstdlib>
#include<iomanip>

using namespace std;

inline void eatline()
{
	while (cin.get() != '\n')
	{
		continue;
	}

}

struct plant
{
	char name[20];
	double population;
	double g;

};

const char* file = "planets.dat";

int main()
{
	plant pl;
	cout << fixed << right;//使用定点计数法和右对齐

	ifstream fin;
	fin.open(file, ios_base::in | ios_base::binary);
	if (fin.is_open())
	{
		cout << "Here are the current contents of the "
			<< file << " file:\n";
			
		while (fin.read((char*)&pl, sizeof pl))
		{
			cout << setw(20) << pl.name << ": "//设置下一个输出的显示宽度
				<< setprecision(0) << setw(12) << pl.population//设置显示精度
				<< setprecision(2) << setw(6) << pl.g << endl;

		}
		fin.close();

	}

	ofstream fout(file, ios_base::out | ios_base::app | ios_base::binary);//二进制的形式追加写入
	if (!fout.is_open())
	{
		cerr << "Can't open " << file << " file for output:\n";
		exit(EXIT_FAILURE);

	}

	cout << "Enter planet name (enter a blank line to quit):\n";
	cin.get(pl.name, 20);
	while (pl.name[0] != '\0')
	{
		eatline();
		cout << "Enter planetary population: ";
		cin >> pl.population;
		cout << "Enter planet's acceleration of gravaity: ";
		cin >> pl.g;

		eatline();
		fout.write((char*)&pl, sizeof pl);//将输入的pl结构内容存储到（写入到）文件中

		cout << "Enter planet name (enter a blank line to quit):\n";
		cin.get(pl.name, 20);



	}
	fout.close();

	fin.clear();
	fin.open(file, ios_base::in | ios_base::binary);
	if (fin.is_open())
	{
		cout << "Here are the current contents of the "
			<< file << " file:\n";

		while (fin.read((char*)&pl, sizeof pl))
		{
			cout << setw(20) << pl.name << ": "//设置下一个输出的显示宽度
				<< setprecision(0) << setw(12) << pl.population//设置显示精度
				<< setprecision(2) << setw(6) << pl.g << endl;

		}
		fin.close();

	}

	cout << "Done.\n";


	system("pause");
	return 0;
}