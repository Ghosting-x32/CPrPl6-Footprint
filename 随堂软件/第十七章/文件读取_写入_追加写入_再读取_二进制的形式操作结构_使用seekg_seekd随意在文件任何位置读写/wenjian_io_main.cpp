#include<iostream>
#include<fstream>
#include<cstdlib>
#include<iomanip>

using namespace std;

const int LIM = 20;

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
	cout << fixed;//默认的cout输出是右对齐

	fstream finout;
	finout.open(file, ios_base::in | ios_base::out | ios_base::binary);

	int ct = 0;

	if (finout.is_open())
	{
		finout.seekg(0);//把读取指针放到文件开始
		cout << "Here are the current contents of the "
			<< file << " file:\n";
		while (finout.read((char*)&pl, sizeof pl))
		{
			cout << ct++ << ": " << setw(LIM) << pl.name
				<< setprecision(0) << setw(12) << pl.population
				<< setprecision(2) << setw(6) << pl.g << endl;

		}

		if (finout.eof())
		{
			finout.clear();
		}
		else
		{
			cerr << "Error in reading " << file << ".\n";
			exit(EXIT_FAILURE);

		}

	}
	else
	{
		cerr << file << " could not be opened -- bye.\n";

		exit(EXIT_FAILURE);

	}

	cout << "Enter the record number you wish to change: ";
	long rec;
	cin >> rec;
	eatline();
	if (rec < 0 || rec >= ct)
	{
		cerr << "Invalid record number -- bye\n";
		exit(EXIT_FAILURE);

	}

	streampos place = rec * sizeof pl;
	finout.seekg(place);//把读取指针放到用户想要读取的位置
	if (finout.fail())
	{

		cerr << "Error on attempted seek\n";
		exit(EXIT_FAILURE);
	}

	finout.read((char*)&pl, sizeof pl);
	cout << "Your selection:\n";
	cout << rec << ": " << setw(LIM) << pl.name << ": "
		<< setprecision(0) << setw(12) << pl.population
		<< setprecision(2) << setw(6) << pl.g << endl;
	if (finout.eof())
	{
		finout.clear();

	}


	cout << "Enter planet name: ";
	cin.get(pl.name, LIM);
	eatline();
	cout << "Enter planetary population: ";
	cin >> pl.population;
	cout << "Enter planet's acceleration of gravity: ";
	cin >> pl.g;
	finout.seekp(place);//把写入指针放到用户想要写入的位置
	finout.write((char*)&pl, sizeof pl) << flush;
	if (finout.fail())
	{
		cerr << "Error on attempted write\n";
		exit(EXIT_FAILURE);
	}

	ct = 0;
	finout.seekg(0);
	cout << "Here are the current contents of the "
		<< file << " file:\n";
	while (finout.read((char*)&pl, sizeof pl))
	{
		cout << ct++ << ": " << setw(LIM) << pl.name
			<< setprecision(0) << setw(12) << pl.population
			<< setprecision(2) << setw(6) << pl.g << endl;

	}
	finout.close();

	cout << "Done.\n";











	system("pause");
	return 0;
}