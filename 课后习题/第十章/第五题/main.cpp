#include<iostream>
#include"stack.h"
using std::cout;
using std::endl;
using std::cin;

int main()
{
	double sum = 0.0;
	Stack st;
	char ch;
	customer cus;
	cout << "Please enter A to add a purchase order,\n"
		<< "P to process a PO, or Q to quit.\n";
	while (cin >> ch && toupper(ch) != 'Q')
	{
		while (cin.get() != '\n')
			continue;
		if (!isalpha(ch))
		{
			cout << '\a';
			cout << "Please enter A to add a purchase order,\n"
				<< "P to process a PO, or Q to quit.\n";
			continue;
		}
		switch (ch)
		{
		case 'a':
		case 'A':
			if (st.isfull())
				cout << "栈已经满了，不能压入任何数据！！\a" << endl;
			else
			{
				cout << "Please enter the customer fullname :";
				cin.getline(cus.fullname, 34);
				cout << "Please enter the customer payment :";
				cin >> cus.payment;
				cin.get();
				st.push(cus);
			}
			break;
		case 'p':
		case 'P':
			if (st.isempty())
				cout << "栈已经空了，不能弹出任何数据！！\a" << endl;
			else
			{
				st.pop(cus);
				sum += cus.payment;
				cout << "payment总数是：" << sum << endl;
			}
			break;
		}
		cout << endl;
		cout << "Please enter A to add a purchase order,\n"
			<< "P to process a PO, or Q to quit.\n";
	}
	cout << "Done!!";


	system("pause");
	return 0;
}
