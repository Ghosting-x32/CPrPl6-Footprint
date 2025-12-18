#include<iostream>
#include<vector>
#include<string>
#include<iterator>
#include<cstddef>
#include<cctype>
#include<stdexcept>





using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::begin;
using std::end;
using std::size_t;
using std::isupper;
using std::runtime_error;





int main()
{
	int val1 = 0, val2 = 0;

	cout << "请输入两个整数:" << endl;

	while (cin >> val1 >> val2)
	{
		try 
		{
			if (val2 == 0)
			{
				throw runtime_error("除数不能为0");
			}
			cout << val1 << " ÷ " << val2 << " = " << val1 / val2 << endl;
		}
		catch (runtime_error err)
		{
			cout << err.what() << "\nTry Again? Enter y or n" << endl;

			char c;
			cin >> c;
			if (!cin || c == 'n')
			{
				break;
			}
		}
		
		cout << "请输入两个整数:" << endl;
	}
	
	



	system("pause");
	return 0;
}