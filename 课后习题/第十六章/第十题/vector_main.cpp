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
bool operator<(const shared_ptr<Review>& r1, const shared_ptr<Review>& r2);//����<��������sort()Ĭ�ϵ���������
bool worseThan(const shared_ptr<Review>& r1, const shared_ptr<Review>& r2);//����sort()�����������汾�Զ����������
bool worseThan1(const shared_ptr<Review>& r1, const shared_ptr<Review>& r2);//����sort()�����������汾�Զ����������


int main()
{
	vector<shared_ptr<Review>> books;
	//˵��1
	 
	//��main�����У��������в���ָ�루��ַ��ʱ�����ܣ���main������newһ��ָ�룬Ȼ������һ�������������ָ��
	//��ȥ�ı����ָ�룬�ٷ������ָ�����������������Ȼֻ�ı���ָ��ָ���ֵ����ʵһֱ����Ķ������ָ���ַ
	//���²���n�����ָ���ַ�����һ�θı�ָ��ָ���ֵ���γ�������n��ָ��ָ��ͬһ���������룩ֵ
	/*vector<Review> books;//temp��Ϊָ�����������
	Review temp;
	while (FillReview(temp))
	{
		books.push_back(temp);//1.push_back()β�巨
	}*/

	//��������һ����������newһ���������͵�ָ�룬���ı���ָ���ֵ���ٷ���main��������һ��������ָ��ȡ���գ��ٲ���������
	//����������ʹ�����ÿһ��ָ���ַ����ͬ��ÿһ��ָ���ַ�����ڱ�ĺ�������new������
	//while (true)
	//{	
	//	shared_ptr<Review> temp = FillReview();
	//	if (!temp)
	//	{
	//		break;
	//	}
	//	books.push_back(temp);//1.push_back()β�巨
	//	
	//}






	while (true)//����˵��1���޸ģ���main�����У�ѭ������new��Ȼ������һ�������ı���ָ���ֵ����������---�߼��������ǿ���ʵ�ֵ�
		//ѭ����֮ǰnew�Ǿ��Բ��е�
	{
		shared_ptr<Review> temp(new Review);		
		if (!FillReview(temp))
		{
			break;
		}

		books.push_back(temp);//1.push_back()β�巨

	}



	int num = books.size();//2.size()������С

	if (num > 0)
	{
		int select = 0;
		while (true)
		{
			cout << "��ѡ������Ҫ���鼮��ʾ��ʽ��" << endl;
			cout << "1.��ԭʼ˳����ʾ" << endl;
			cout << "2.����ĸ��˳����ʾ" << endl;
			cout << "3.������������ʾ" << endl;
			cout << "4.������������ʾ" << endl;
			cout << "5.���۸�������ʾ" << endl;
			cout << "6.���۸�����ʾ" << endl;
			cout << "7.�˳�" << endl;

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
				cout << "�˳��ɹ���" << endl;
				break;
			}
			else
			{
				cout << "�����������������룡" << endl;
				continue;
			}

		}



		//cout << "Thank you . You entered the following:\n";
		//cout << "Rating\tBook\n";
		//for_each(books.begin(), books.end(), ShowReview);//1-1.for_each()�����㷨

		//sort(books.begin(), books.end());//1-2.sort()�����㷨
		//cout << "Sorted by title:\nRating\tBook\n";
		//for_each(books.begin(), books.end(), ShowReview);

		//sort(books.begin(), books.end(), worseThan);
		//cout << "Sorted by rating:\nRating\tBook\n";
		//for_each(books.begin(), books.end(), ShowReview);

		////random_shuffle()�㷨��c++17��׼���ѱ��Ƴ�������ʹ�ý�������������shuffle()
		//shuffle(books.begin(), books.end(), gen);//1-3.shuffle()��������㷨----ϴ��
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
//	cout << "�����������ַ���ʼ ('q' to quit): ";
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
//	/*if (rr.title == "quit")����ĳһ��title����quit,���Ըĵ���������ķ���
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
	getline(cin, rr->title);
	/*if (rr.title == "quit")����ĳһ��title����quit,���Ըĵ���������ķ���
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