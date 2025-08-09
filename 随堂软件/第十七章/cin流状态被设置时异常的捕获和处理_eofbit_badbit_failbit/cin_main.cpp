#include<iostream>
#include<exception>


using namespace std;

int main()
{
	cin.exceptions(ios_base::failbit);//failbit流状态被设置将引发异常----输入与预期格式不匹配

	cout << "Enter numbers: ";

	int sum = 0;
	int input;
	try
	{
		while (cin >> input)
		{
			sum += input;


		}
	}
	catch (ios_base::failure& bf)//failure异常类是exception异常类派生的
	{
		cout << bf.what() << endl;
		cout << "O! the horror!\n";

	}

	cout << "Last value entered = " << input << endl;
	cout << "Sum = " << sum << endl;






	system("pause");
	return 0;
}