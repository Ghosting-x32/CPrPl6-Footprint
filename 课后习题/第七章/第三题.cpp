#include<iostream>
struct box
{
	char maker[40];
	float height;
	float width;
	float length;
	float volume;
};

void f1(box);
void f2(box* ad);

int main()
{
	using namespace std;
	box aj =
	{
		"haodongxi",
		36.2,
		23.6,
		36.5,
		0.0
	};
	f1(aj);
	f2(&aj);
	f1(aj);






	cout << endl;
	system("pause");
	return 0;
}

void f1(box ar)
{
	using namespace std;
	cout << ar.maker << endl
		<< ar.height << endl
		<< ar.width << endl
		<< ar.length << endl
		<< ar.volume << endl;
}

void f2(box* ad)
{
	ad->volume = ad->height * ad->width * ad->length;
}