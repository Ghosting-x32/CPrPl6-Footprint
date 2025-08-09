#include<iostream>
#include<string>
#include<vector>

using namespace std;

struct Review
{
	string title;
	int rating;
};


bool FillReview(Review& rr);
void ShowReview(const Review& rr);


int main()
{
	vector<Review> books;
	Review temp;
	while (FillReview(temp))
	{
		books.push_back(temp);//1.push_back()β�巨
	}

	int num = books.size();//2.size()������С

	if (num > 0)
	{
		cout << "Thank you . You entered the following:\n";
		cout << "Rating\tBook\n";
		for (int i = 0; i < num; i++)
		{
			ShowReview(books[i]);
		}

		cout << "Reprising\n";
		cout << "Rating\tBook\n";
		vector<Review>::iterator pr;//��������������ʼ����ʹ��
		for (pr = books.begin(); pr != books.end(); pr++)
		{
			ShowReview(*pr);
		}

		vector<Review> oldlist(books);
		if (num > 3)
		{
			books.erase(books.begin() + 1, books.begin() + 3);//3.erase()ɾ���������ṩ�������Ԫ��
			cout << "After erasure:\n";
			for (pr = books.begin(); pr != books.end(); pr++)
			{
				ShowReview(*pr);
			}

			books.insert(books.begin(), oldlist.begin() + 1, oldlist.begin() + 2);//4.insert()��ָ��λ�ò�����һ������ָ�����������Ԫ��
			cout << "After insertion:\n";
			for (pr = books.begin(); pr != books.end(); pr++)//5.begin()��ʼλ��
			{
				ShowReview(*pr);
			}


		}
		books.swap(oldlist);//6.swap()����������������Ԫ��
		cout << "Swappint oldlist with books:\n";

		for (pr = books.begin(); pr != books.end(); pr++)//7.end()���һ��Ԫ�صĺ�һ��λ��
		{
			ShowReview(*pr);
		}


	}
	else
	{
		cout << "Nothing entered, nothing gained.\n";
	}



	system("pause");
	return 0;
}


bool FillReview(Review& rr)
{
	//cout << "Enter book title (quit to quit): ";
	cout << "�����������ַ���ʼ ('q' to quit): ";
	char ch;
	cin >> ch;
	while (cin.get() != '\n')
	{
		continue;

	}
	if (ch == 'q')
	{
		return false;
	}

	cout << "Enter book title: ";
	getline(cin, rr.title);
	/*if (rr.title == "quit")����ĳһ��title����quit,���Ըĵ���������ķ���
	{
		return false;
	}*/

	cout << "Enter book rating: ";


	while (!(cin >> rr.rating))
	{
		cin.clear();
		while (cin.get() != '\n')
		{
			continue;
		}
		cout << "Input error, please enter a number!" << endl;
	}



	/*cin >> rr.rating;
	if (!cin)
	{
		return false;
	}*/
	while (cin.get() != '\n')
	{
		continue;

	}

	return true;


}


void ShowReview(const Review& rr)
{

	cout << rr.rating << "\t" << rr.title << endl;

}