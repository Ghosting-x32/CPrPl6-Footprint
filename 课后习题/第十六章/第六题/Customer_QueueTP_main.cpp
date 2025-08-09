#include<iostream>
#include<random>
#include<string>
#include<queue>


#include"Customer.h"

using namespace std;

const int MIN_PER_HR = 60;

bool newcustomer(double x);




int main()
{
	char ch;
	cout << "请输入任意字符开始测试，q代表退出测试!" << endl;
	while (cin >> ch && ch != 'q')
	{
		while (cin.get() != '\n')
		{
			continue;
		}
		cout << "Case Study: Bank of Heather Automatic Teller\n";
		cout << "Enter maximum size of queue: ";
		int qs;
		//cin >> qs;
		while (!(cin >> qs))
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
		queue<Customer> line;

		cout << "Enter the number of simulation hours: ";
		int hours;
		//cin >> hours;
		while (!(cin >> hours))
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
		long cyclelimit = MIN_PER_HR * hours;

		cout << "Enter the acerage number of customers per hour: ";
		double perhour;
		//cin >> perhour;
		while (!(cin >> perhour))
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
		double min_per_cust;
		min_per_cust = MIN_PER_HR / perhour;

		Customer temp;
		long turnaways = 0;
		long customers = 0;
		long served = 0;
		long sum_line = 0;
		int wait_time = 0;
		long line_wait = 0;

		for (int cycle = 0; cycle < cyclelimit; cycle++)
		{
			if (newcustomer(min_per_cust))
			{
				if (line.size() >= qs)
					turnaways++;
				else
				{
					customers++;
					temp.set(cycle);
					line.push(temp);
				}
			}
			if (wait_time <= 0 && !line.empty())
			{

				
				temp = line.front();
				wait_time = temp.ptime();
				line_wait += cycle - temp.when();
				served++;
				line.pop();
			}
			if (wait_time > 0)
				wait_time--;
			sum_line += line.size();
		}

		if (customers > 0)
		{
			cout << "customers accepted: " << customers << endl;
			cout << "customers served: " << served << endl;
			cout << "turnaways: " << turnaways << endl;
			cout << "average queue size: ";
			cout.precision(2);
			cout.setf(ios_base::fixed, ios_base::floatfield);
			cout << (double)sum_line / cyclelimit << endl;
			cout << " average wait time: "
				<< (double)line_wait / served << endl;
		}
		else
			cout << "No customers!\n";
		cout << "Done!" << endl;

		cout << "请输入任意字符开始测试，q代表退出测试!" << endl;
	}

	


	system("pause");
	return 0;
}

bool newcustomer(double x)
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<>dis(1, 10000);


	return ((dis(gen) * x / 10000) < 1);
}