#include <iostream>           //结构的赋值
struct inflatable
{
	char name[20];
	float volume;
	double price;
};

int main()
{
	using namespace std;
	inflatable bouquet =
	{
		"sunflowers",
		0.20,
		12.49
	};
	inflatable choice;
	cout << "bouquet: " << bouquet.name << " for $";
	cout << bouquet.price << endl;

	choice = bouquet;
	cout << "choece: " << choice.name << " for $";
	cout << choice.price << endl;
	cin.get();
	cin.get();
	return 0;
}
