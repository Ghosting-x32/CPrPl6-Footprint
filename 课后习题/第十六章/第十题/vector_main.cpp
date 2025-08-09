#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<memory>


using namespace std;

struct Review
{
	string title;
	int rating;
	double price;
};


//shared_ptr<Review> FillReview();
bool FillReview(shared_ptr<Review>& rr);
void ShowReview(const shared_ptr<Review>& rr);
bool operator<(const shared_ptr<Review>& r1, const shared_ptr<Review>& r2);//重载<符号用于sort()默认的升序排序
bool worseThan(const shared_ptr<Review>& r1, const shared_ptr<Review>& r2);//用于sort()的三个参数版本自定义排序规则
bool worseThan1(const shared_ptr<Review>& r1, const shared_ptr<Review>& r2);//用于sort()的三个参数版本自定义排序规则


int main()
{
	vector<shared_ptr<Review>> books;
	//说法1
	 
	//在main函数中，向容器中插入指针（地址）时，不能：在main函数中new一个指针，然后让另一个函数接受这个指针
	//再去改变这个指针，再返回这个指针插入容器！这样显然只改变了指针指向的值，其实一直插入的都是这个指针地址
	//导致插入n个这个指针地址，最后一次改变指针指向的值，形成容器中n个指针指向同一个（最后插入）值
	/*vector<Review> books;//temp变为指针后不能这样做
	Review temp;
	while (FillReview(temp))
	{
		books.push_back(temp);//1.push_back()尾插法
	}*/

	//必须在另一个函数里面new一个这种类型的指针，并改变其指向的值，再返回main函数中用一个这样的指针取接收，再插入容器中
	//这样做才能使插入的每一个指针地址都不同，每一个指针地址都是在别的函数里面new出来的
	//while (true)
	//{	
	//	shared_ptr<Review> temp = FillReview();
	//	if (!temp)
	//	{
	//		break;
	//	}
	//	books.push_back(temp);//1.push_back()尾插法
	//	
	//}






	while (true)//对于说法1做修改：在main函数中，循环体内new，然后用另一个函数改变其指向的值，再做插入---逻辑理清析是可以实现的
		//循环体之前new是绝对不行的
	{
		shared_ptr<Review> temp(new Review);		
		if (!FillReview(temp))
		{
			break;
		}

		books.push_back(temp);//1.push_back()尾插法

	}



	int num = books.size();//2.size()容器大小

	if (num > 0)
	{
		int select = 0;
		while (true)
		{
			cout << "请选择你想要的书籍显示方式：" << endl;
			cout << "1.按原始顺序显示" << endl;
			cout << "2.按字母表顺序显示" << endl;
			cout << "3.按评级升序显示" << endl;
			cout << "4.按评级降序显示" << endl;
			cout << "5.按价格升序显示" << endl;
			cout << "6.按价格降序显示" << endl;
			cout << "7.退出" << endl;

			while (!(cin >> select))
			{
				cin.clear();
				while (cin.get() != '\n')
				{
					continue;
				}
				cout << "Input error, please enter a number!" << endl;

			}
			while (cin.get() != '\n')
			{
				continue;
			}

			if (select == 1)
			{
				vector<shared_ptr<Review>> books1(books);
				for_each(books1.begin(), books1.end(), ShowReview);
				cout << endl;

			}
			else if (select == 2)
			{
				vector<shared_ptr<Review>> books2(books);
				sort(books2.begin(), books2.end());
				for_each(books2.begin(), books2.end(), ShowReview);
				cout << endl;


			}
			else if (select == 3)
			{
				vector<shared_ptr<Review>> books3(books);
				sort(books3.begin(), books3.end(), worseThan);
				for_each(books3.begin(), books3.end(), ShowReview);
				cout << endl;


			}
			else if (select == 4)
			{
				vector<shared_ptr<Review>> books3(books);
				sort(books3.begin(), books3.end(), worseThan);
				for_each(books3.rbegin(), books3.rend(), ShowReview);
				cout << endl;


			}
			else if (select == 5)
			{
				vector<shared_ptr<Review>> books3(books);
				sort(books3.begin(), books3.end(), worseThan1);
				for_each(books3.begin(), books3.end(), ShowReview);
				cout << endl;


			}
			else if (select == 6)
			{
				vector<shared_ptr<Review>> books3(books);
				sort(books3.begin(), books3.end(), worseThan1);
				for_each(books3.rbegin(), books3.rend(), ShowReview);
				cout << endl;


			}
			else if (select == 7)
			{
				cout << "退出成功！" << endl;
				break;
			}
			else
			{
				cout << "输入有误，请重新输入！" << endl;
				continue;
			}

		}



		//cout << "Thank you . You entered the following:\n";
		//cout << "Rating\tBook\n";
		//for_each(books.begin(), books.end(), ShowReview);//1-1.for_each()遍历算法

		//sort(books.begin(), books.end());//1-2.sort()排序算法
		//cout << "Sorted by title:\nRating\tBook\n";
		//for_each(books.begin(), books.end(), ShowReview);

		//sort(books.begin(), books.end(), worseThan);
		//cout << "Sorted by rating:\nRating\tBook\n";
		//for_each(books.begin(), books.end(), ShowReview);

		////random_shuffle()算法在c++17标准中已被移除，现在使用结束三个参数的shuffle()
		//shuffle(books.begin(), books.end(), gen);//1-3.shuffle()随机打乱算法----洗牌
		//cout << "After shuffling:\nRating\tBook\n";
		//for_each(books.begin(), books.end(), ShowReview);




	}
	else
	{
		cout << "Nothing entered, nothing gained.\n";
	}



	system("pause");
	return 0;
}


//shared_ptr<Review> FillReview()
//{
//	//cout << "Enter book title (quit to quit): ";
//	cout << "请输入任意字符开始 ('q' to quit): ";
//	char ch;
//	cin >> ch;
//	while (cin.get() != '\n')
//	{
//		continue;
//
//	}
//	if (ch == 'q')
//	{
//		return nullptr;
//	}
//
//	shared_ptr<Review> rr(new Review);
//
//	cout << "Enter book title: ";
//	getline(cin, rr->title);
//	/*if (rr.title == "quit")可能某一个title就是quit,所以改掉结束输入的方法
//	{
//		return false;
//	}*/
//
//	cout << "Enter book rating: ";
//
//
//	while (!(cin >> rr->rating))
//	{
//		cin.clear();
//		while (cin.get() != '\n')
//		{
//			continue;
//		}
//		cout << "Input error, please enter a number!" << endl;
//	}
//
//
//
//	/*cin >> rr.rating;
//	if (!cin)
//	{
//		return false;
//	}*/
//	while (cin.get() != '\n')
//	{
//		continue;
//
//	}
//
//	cout << "Enter book price: ";
//	while (!(cin >> rr->price))
//	{
//		cin.clear();
//		while (cin.get() != '\n')
//		{
//			continue;
//		}
//		cout << "Input error, please enter a number!" << endl;
//	}
//	while (cin.get() != '\n')
//	{
//		continue;
//
//	}
//
//	return rr;
//
//
//}







bool FillReview(shared_ptr<Review>& rr)
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
	getline(cin, rr->title);
	/*if (rr.title == "quit")可能某一个title就是quit,所以改掉结束输入的方法
	{
		return false;
	}*/

	cout << "Enter book rating: ";


	while (!(cin >> rr->rating))
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

	cout << "Enter book price: ";
	while (!(cin >> rr->price))
	{
		cin.clear();
		while (cin.get() != '\n')
		{
			continue;
		}
		cout << "Input error, please enter a number!" << endl;
	}
	while (cin.get() != '\n')
	{
		continue;

	}

	return true;


}

void ShowReview(const shared_ptr<Review>& rr)
{

	cout << rr->rating << "\t" << rr->title << "\t" << rr->price << endl;

}


bool operator<(const shared_ptr<Review>& r1, const shared_ptr<Review>& r2)
{
	if (r1->title < r2->title)
	{
		return true;
	}
	else if (r1->title == r2->title && r1->rating < r2->rating)
	{
		return true;
	}
	else
	{
		return false;
	}
}


bool worseThan(const shared_ptr<Review>& r1, const shared_ptr<Review>& r2)
{
	if (r1->rating < r2->rating)
	{
		return true;
	}
	else
	{
		return false;
	}
}


bool worseThan1(const shared_ptr<Review>& r1, const shared_ptr<Review>& r2)
{
	if (r1->price < r2->price)
	{
		return true;
	}
	else
	{
		return false;
	}
}