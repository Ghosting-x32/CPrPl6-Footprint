#include<iostream>
#include<fstream>


using namespace std;



int main(int argc, char* argv[])
{
	
	ofstream fout(argv[1]);
	char ch;
	cout << "ÇëÊäÈëÒ»Ð©×Ö·û£º" << endl;

	while (cin.get(ch))
	{
		fout.put(ch);
	}



	cout << "Done!" << endl;







	system("pause");
	return 0;
}

