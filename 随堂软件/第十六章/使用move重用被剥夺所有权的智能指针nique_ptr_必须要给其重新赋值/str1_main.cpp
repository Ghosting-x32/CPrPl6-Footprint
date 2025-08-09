#include<iostream>
#include<string>
#include<memory>



using namespace std;

unique_ptr<string> demo(const char* s);

int main()
{
	unique_ptr<string> ps1, ps2;
	ps1 = demo("Uniquely special");
	ps2 = move(ps1);
	//ps1 = demo(" and more");
	ps1 = unique_ptr<string>(new string("込込込込"));
	cout << *ps2 << *ps1 << endl;




	system("pause");
	return 0;
}

unique_ptr<string> demo(const char* s)
{
	unique_ptr<string> temp(new string(s));
	return temp;


}