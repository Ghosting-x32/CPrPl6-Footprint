#include<iostream>
#include<fstream>


using namespace std;



int main(int argc, char* argv[])
{
	ifstream fin1;
	fin1.open("eggs.txt");
	ifstream fin2;
	fin2.open("zero.txt");
	ofstream fout("hb.txt");

	char temp1[100];
	
	char temp2[100];
	

	while (!fin1.eof() || !fin2.eof())
	{
		
		if (!fin1.eof() && !fin2.eof())
		{
			fin1.getline(temp1, 100);
			fin2.getline(temp2, 100);
			fout << temp1 << " " << temp2 << endl;
		
		}
		else if (fin1.eof() && !fin2.eof())
		{
			fin2.getline(temp2, 100);
			fout << temp2 << endl;
			
		}
		else if (!fin1.eof() && fin2.eof())
		{
			fin1.getline(temp1, 100);
			fout << temp1 << endl;
			
		}
		
	}

	fin1.close();
	fin2.close();
	fout.close();



	cout << "Done!" << endl;

	system("pause");
	return 0;
}




