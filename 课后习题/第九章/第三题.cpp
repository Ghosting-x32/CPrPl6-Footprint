#include<iostream>
const int BUF = 512;
struct chaff
{
	char dross[20];
	int slag;
};
char buffer[BUF];

int main()
{
	using namespace std;
	chaff* cs = new (buffer) chaff[2];
	strcpy_s(cs[0].dross, "haodongxi");
	strcpy_s(cs[1].dross, "buhaode");
	cs[0].slag = 365;
	cs[1].slag = 562;
	for (int i = 0; i < 2; i++)
		cout << cs[i].dross << ": " << cs[i].slag << "." << endl;





	system("pause");
	return 0;
}