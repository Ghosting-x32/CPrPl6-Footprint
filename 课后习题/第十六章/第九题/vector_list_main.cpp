#include<iostream>
#include<string>
#include<vector>
#include<list>
#include<algorithm>
#include<iterator>
#include<ctime>
#include<random>

using namespace std;
void show(const int n);

int main()
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dis(0, 100000000);

	vector<int> vi0;
	for (int i = 0; i < 1000000; i++)//����һ�����Ԫ��
	{
		vi0.push_back(dis(gen));
	}
	//for_each(vi0.begin(), vi0.end(), show);
	//cout << endl;

	vector<int> vi;
	list<int> li;

	copy(vi0.begin(), vi0.end(), insert_iterator<vector<int>>(vi, vi.begin()));
	//for_each(vi.begin(), vi.end(), show);
	//cout << endl;

	copy(vi0.begin(), vi0.end(), insert_iterator<list<int>>(li, li.begin()));
	//for_each(li.begin(), li.end(), show);
	//cout << endl;

	//1.vector������sort�㷨��������ʱ�����
	clock_t start = clock();
	sort(vi.begin(), vi.end());
	clock_t end = clock();
	clock_t vi_sort = (double)(end * 1000 - start * 1000)  / CLOCKS_PER_SEC ;//���������ڲ�׽��������ʱ��
	cout << "vi_sort = " << vi_sort << endl;

	//2.list�������Դ�sort��Ա������������ʱ�����
	clock_t start_li = clock();
	li.sort();
	clock_t end_li = clock();
	clock_t li_sort = (double)(end_li * 1000 - start_li * 1000) / CLOCKS_PER_SEC;
	cout << "li_sort = " << li_sort << endl;

	//3.list���������ݸ��Ƶ�vector��������sort�㷨������ٸ��Ƶ�list��������ʱ�����
	list<int>li1;
	vector<int> vi1;
	copy(vi0.begin(), vi0.end(), insert_iterator<list<int>>(li1, li1.begin()));

	clock_t start_li1 = clock();
	copy(li1.begin(), li1.end(), insert_iterator<vector<int>>(vi1, vi1.begin()));	
	//for_each(li1.begin(), li1.end(), show);
	//cout << endl;
	sort(vi1.begin(), vi1.end());
	copy(vi1.begin(), vi1.end(), li1.begin());
	//for_each(li1.begin(), li1.end(), show);
	//cout << endl;
	clock_t end_li1 = clock();
	clock_t li_sort1 = (double)(end_li1 * 1000 - start_li1 * 1000) / CLOCKS_PER_SEC;
	cout << "���Ƶ�vector�����ٸ��ƻ�list: li_sort = " << li_sort1 << endl;









	system("pause");
	return 0;
}


void show(const int n)
{

	cout << n << " ";
}