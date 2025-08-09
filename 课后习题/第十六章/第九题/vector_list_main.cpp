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
	for (int i = 0; i < 1000000; i++)//储存一百万个元素
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

	//1.vector容器用sort算法排序所花时间测试
	clock_t start = clock();
	sort(vi.begin(), vi.end());
	clock_t end = clock();
	clock_t vi_sort = (double)(end * 1000 - start * 1000)  / CLOCKS_PER_SEC ;//扩大倍数用于捕捉程序运行时间
	cout << "vi_sort = " << vi_sort << endl;

	//2.list容器用自带sort成员函数排序所花时间测试
	clock_t start_li = clock();
	li.sort();
	clock_t end_li = clock();
	clock_t li_sort = (double)(end_li * 1000 - start_li * 1000) / CLOCKS_PER_SEC;
	cout << "li_sort = " << li_sort << endl;

	//3.list容器的内容复制到vector容器内用sort算法排序后再复制到list容器所花时间测试
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
	cout << "复制到vector排序再复制回list: li_sort = " << li_sort1 << endl;









	system("pause");
	return 0;
}


void show(const int n)
{

	cout << n << " ";
}