#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<iterator>
#include<fstream>

using namespace std;

void show(const string& st);
void show1(const string& st);

int main()
{
	set<string> Mat;
	set<string> Pat;
	set<string> Mat_Pat;
	string temp;
	string temp1;

	ifstream finmat;
	finmat.open("mat.dat");
	ifstream finpat;
	finpat.open("pat.dat");
	


	
	while (getline(finmat, temp))
	{
		Mat.insert(temp);
		
	}
	finmat.close();
	cout << "Mat的朋友展示如下：" << endl;
	for_each(Mat.begin(), Mat.end(), show1);


	
	while (getline(finpat, temp1))
	{
		Pat.insert(temp1);
		
	}
	finpat.close();
	cout << "\nPat的朋友展示如下：" << endl;
	for_each(Pat.begin(), Pat.end(), show1);



	set_union(Mat.begin(), Mat.end(), Pat.begin(), Pat.end(), insert_iterator<set<string>>(Mat_Pat, Mat_Pat.begin()));
	//集合算合集并插到第三个集合中
	cout << "\nMat和Pat的朋友展示如下：" << endl;
	for_each(Mat_Pat.begin(), Mat_Pat.end(), show1);

	for_each(Mat_Pat.begin(), Mat_Pat.end(), show);
	cout << "\n写入成功！" << endl;

	system("pause");
	return 0;
}



void show(const string& st)
{
	ofstream fout("matnpat.dat", ios_base::out | ios_base::app);

	fout << st << endl;
	fout.close();
}

void show1(const string& st)
{

	cout << st << ",";
}