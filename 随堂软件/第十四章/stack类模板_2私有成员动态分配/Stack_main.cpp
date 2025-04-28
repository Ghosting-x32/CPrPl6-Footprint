#include<iostream>
#include<string>
#include<random>

#include"Stack.h"

using namespace std;

const int Num = 10;

int main()
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<>dis(0, 1);

	
	

	cout << "Please enter stack size: ";
	int stacksize;
	while (!(cin >> stacksize))
	{
		cin.clear();
		while (cin.get() != '\n')
		{
			continue;
		}
		cout << "Incorrect input, please enter a number!" << endl;
	}
	
	while (cin.get() != '\n')
	{
		continue;
	}

	Stack<const char*>st(stacksize);


	const char* in[Num] =
	{
		"1: Hank Gilgamesh", "2: Kiki Ishtar",
		"3: Betty Rocker", "4: Ian Flagranti",
		"5: Wolfgang Kibble", "6: Portia koop",
		"7: Joy Almondo", "8: Xaverie Paprika",
		"9: Juan Moore", "10: Misha Mache"
	};

	const char* out[Num];


	int processed = 0;
	int nextin = 0;

	while (processed < Num)
	{
		if (st.isempty())
		{
			st.push(in[nextin++]);
		}
		else if (st.isfull())
		{
			st.pop(out[processed++]);
		}
		else if (dis(gen) && nextin < Num)
		{
			st.push(in[nextin++]);
		}
		else
		{
			st.pop(out[processed++]);
		}

	}



	for (int i = 0; i < Num; i++)
	{
		cout << out[i] << endl;
	}



	system("pause");
	return 0;
}