#include<iostream>
#include<string>
#include<algorithm>
#include<iterator>
#include<set>



using namespace std;



int main()
{
	const int N = 6;
	string s1[N] = { "buffoon", "thinkers", "for", "heavy", "can", "for" };
	string s2[N] = { "metal", "any", "food", "elegant", "deliver", "for" };

	set<string> A(s1, s1 + N);
	set<string> B(s2, s2 + N);

	ostream_iterator<string, char> out(cout, " ");//声明一个输出迭代器
	cout << "Set A: ";
	copy(A.begin(), A.end(), out);
	cout << endl << "Set B: ";
	copy(B.begin(), B.end(), out);

	cout << endl << "Union of A and B:\n";
	set_union(A.begin(), A.end(), B.begin(), B.end(), out);//并集----A并B

	cout << endl << "Intersection of Aand B:\n";
	set_intersection(A.begin(), A.end(), B.begin(), B.end(), out);//交集---A交B

	cout << endl << "Difference of Aand B: \n";
	set_difference(A.begin(), A.end(), B.begin(), B.end(), out);//差集---A - B(A里面去除B中拥有的元素)
	cout << endl;

	set<string> C;
	insert_iterator<set<string>> temp(C, C.begin());
	//set_union(A.begin(), A.end(), B.begin(), B.end(), insert_iterator<set<string>>(C, C.begin()));//使用里匿名的插入迭代器（输出迭代器概念模型）
	set_union(A.begin(), A.end(), B.begin(), B.end(), temp);
	copy(C.begin(), C.end(), out);
	cout << endl;

	string s3("grungy");
	C.insert(s3);
	cout << "Set C after insertoin:\n";
	copy(C.begin(), C.end(), out);
	cout << endl;

	cout << "Showing a rande:\n";
	copy(C.lower_bound("ghost"), C.upper_bound("spook"), out);//ASCII码大小排列在这个区间的内容("ghost","spook")
	//lower_bound()返回指向第一个大于"ghost"的迭代器
	//upper_bound()返回指向第一个小于"spook"的迭代器
	cout << endl;


	

	system("pause");
	return 0;
}


