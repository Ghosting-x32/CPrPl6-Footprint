#include<iostream>
#include<string>
#include<memory>



using namespace std;

void text1();
void text2();

int main()
{
	text1();
	cout << "=================================" << endl;
	text2();



	system("pause");
	return 0;
}

void text1()
{
	unique_ptr<string> films[5] =
	{
		unique_ptr<string>(new string("Fowl Balls")),
		unique_ptr<string>(new string("Duck Walks")),
		unique_ptr<string>(new string("Chicken Runs")),
		unique_ptr<string>(new string("Turkey Errors")),
		unique_ptr<string> (new string("Coose Eggs")),

	};

	//unique_ptr<string> pwin;
	//pwin = films[2];//赋值操作转让所有权，unique_ptr不允许这样做，导致程序无法运行
	//老版auto_ptr允许这样做，但导致films[2]所有权转让给pwin，导致films[2]不能访问Chicken Runs字符串
	//输出films[2]时出现不确定错误

	cout << "The nominees for best avian baseball film are\n";
	for (int i = 0; i < 5; i++)
	{

		cout << *films[i] << endl;
	}

	//cout << "The winner is " << *pwin << "!\n";



}


void text2()
{
	shared_ptr<string> films[5] =
	{
		shared_ptr<string>(new string("Fowl Balls")),
		shared_ptr<string>(new string("Duck Walks")),
		shared_ptr<string>(new string("Chicken Runs")),
		shared_ptr<string>(new string("Turkey Errors")),
		shared_ptr<string>(new string("Coose Eggs")),

	};

	shared_ptr<string> pwin;//shared_ptr解决了所有权转让问题
	pwin = films[2];

	cout << "The nominees for best avian baseball film are\n";
	for (int i = 0; i < 5; i++)
	{

		cout << *films[i] << endl;
	}

	cout << "The winner is " << *pwin << "!\n";


}