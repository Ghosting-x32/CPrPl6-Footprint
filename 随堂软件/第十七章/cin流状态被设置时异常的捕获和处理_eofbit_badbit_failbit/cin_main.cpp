#include<iostream>
#include<exception>


using namespace std;

int main()
{
	cin.exceptions(ios_base::failbit);//failbit��״̬�����ý������쳣----������Ԥ�ڸ�ʽ��ƥ��

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
	catch (ios_base::failure& bf)//failure�쳣����exception�쳣��������
	{
		cout << bf.what() << endl;
		cout << "O! the horror!\n";

	}

	cout << "Last value entered = " << input << endl;
	cout << "Sum = " << sum << endl;






	system("pause");
	return 0;
}