#include<iostream>
#include<string>
#include<vector>

using namespace std;

const int NUM = 5;


int main()
{
	vector<int> ratings(NUM);
	vector<string> titles(NUM);

	cout << "Ywill do exactly as told. You will enter\n";
	cout << NUM << " book titles and your ratings (0-10).\n";
	int i;
	for (i = 0; i < NUM; i++)
	{
		cout << "Enter title #" << i + 1 << ": ";
		getline(cin, titles[i]);
		cout << "Enter your rating (0-10): ";

		while (true)
		{
			while (!(cin >> ratings[i]))
			{
				cin.clear();
				while (cin.get() != '\n')
				{
					continue;
				}
				cout << "Input error, please enter a number!" << endl;
			}

			while (cin.get() != '\n')
			{
				continue;
			}


			if (ratings[i] > 10 || ratings[i] < 0)
			{
				cout << "Input error,Enter your rating (0-10):";
				continue;
			}
			else
			{
				break;
			}
		}

		

	}
	cout << "Thank you .You entered the following:\n"
		<< "Rating\tBook\n";

	for (i = 0; i < NUM; i++)
	{
		cout << ratings[i] << "\t" << titles[i] << endl;

	}




	system("pause");
	return 0;
}


