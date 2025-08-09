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

	ostream_iterator<string, char> out(cout, " ");//����һ�����������
	cout << "Set A: ";
	copy(A.begin(), A.end(), out);
	cout << endl << "Set B: ";
	copy(B.begin(), B.end(), out);

	cout << endl << "Union of A and B:\n";
	set_union(A.begin(), A.end(), B.begin(), B.end(), out);//����----A��B

	cout << endl << "Intersection of Aand B:\n";
	set_intersection(A.begin(), A.end(), B.begin(), B.end(), out);//����---A��B

	cout << endl << "Difference of Aand B: \n";
	set_difference(A.begin(), A.end(), B.begin(), B.end(), out);//�---A - B(A����ȥ��B��ӵ�е�Ԫ��)
	cout << endl;

	set<string> C;
	insert_iterator<set<string>> temp(C, C.begin());
	//set_union(A.begin(), A.end(), B.begin(), B.end(), insert_iterator<set<string>>(C, C.begin()));//ʹ���������Ĳ�����������������������ģ�ͣ�
	set_union(A.begin(), A.end(), B.begin(), B.end(), temp);
	copy(C.begin(), C.end(), out);
	cout << endl;

	string s3("grungy");
	C.insert(s3);
	cout << "Set C after insertoin:\n";
	copy(C.begin(), C.end(), out);
	cout << endl;

	cout << "Showing a rande:\n";
	copy(C.lower_bound("ghost"), C.upper_bound("spook"), out);//ASCII���С������������������("ghost","spook")
	//lower_bound()����ָ���һ������"ghost"�ĵ�����
	//upper_bound()����ָ���һ��С��"spook"�ĵ�����
	cout << endl;


	

	system("pause");
	return 0;
}


