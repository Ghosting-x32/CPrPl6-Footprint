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
		books.push_back(temp);//1.push_back()尾插法
	}

	int num = books.size();//2.size()容器大小

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
		vector<Review>::iterator pr;//迭代器的声明初始化与使用
		for (pr = books.begin(); pr != books.end(); pr++)
		{
			ShowReview(*pr);
		}

		vector<Review> oldlist(books);
		if (num > 3)
		{
			books.erase(books.begin() + 1, books.begin() + 3);//3.erase()删除容器内提供区间里的元素
			cout << "After erasure:\n";
			for (pr = books.begin(); pr != books.end(); pr++)
			{
				ShowReview(*pr);
			}

			books.insert(books.begin(), oldlist.begin() + 1, oldlist.begin() + 2);//4.insert()在指定位置插入另一个容器指定区间的所有元素
			cout << "After insertion:\n";
			for (pr = books.begin(); pr != books.end(); pr++)//5.begin()起始位置
			{
				ShowReview(*pr);
			}


		}
		books.swap(oldlist);//6.swap()两个容器互换所有元素
		cout << "Swappint oldlist with books:\n";

		for (pr = books.begin(); pr != books.end(); pr++)//7.end()最后一个元素的后一个位置
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
	cout << "请输入任意字符开始 ('q' to quit): ";
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
	/*if (rr.title == "quit")可能某一个title就是quit,所以改掉结束输入的方法
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