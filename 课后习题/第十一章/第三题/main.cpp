#include<iostream>
#include<cstdlib>
#include<ctime>
#include<vector>
#include"vect.h"


int main()
{
	using std::cout;
	using std::cin;
	using std::endl;
	using std::vector;
	using VECTOR::Vector;
	double direction;
	Vector step;
	Vector result(0.0, 0.0);
	unsigned long steps = 0;
	double target;
	double dstep;
	int N = 0;

	cout << "请输入你要测试的次数：";
	cin >> N;
	vector<unsigned long>stepsz(N);
	srand(time(0));
	cout << "Enter target distance: ";
	cin >> target;

	cout << "Enter step length: ";
	cin >> dstep;
	for (int i = 0; i < N; i++)
	{

		while (result.magval() < target)
		{
			direction = rand() % 360;
			step.reset(dstep, direction, Vector::POL);
			result = result + step;
			steps++;
		}
		stepsz[i] = steps;
		steps = 0;
		result.reset(0.0, 0.0);
	}
	unsigned long stepszd = stepsz[0];
	for (int i = 1; i < N; i++)
	{
		stepszd = stepszd > stepsz[i] ? stepszd : stepsz[i];
	}
	cout << N << " 次测试中，最高步数是：" << stepszd << endl;
	unsigned long stepszx = stepsz[0];
	for (int i = 1; i < N; i++)
	{
		stepszx = stepszx < stepsz[i] ? stepszx : stepsz[i];
	}
	cout << N << " 次测试中，最低步数是：" << stepszx << endl;
	unsigned long stepszpj = stepsz[0];
	for (int i = 1; i < N; i++)
	{
		stepszpj += stepsz[i];
	}
	cout << N << " 次测试中，平均步数是：" << stepszpj / N << endl;








	
	cout << "Bye!\n";
	cin.clear();
	while (cin.get() != '\n')
		continue;
	system("pause");
	return 0;
}
