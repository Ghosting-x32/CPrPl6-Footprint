#include<iostream>
#include<string>
#include<vector>
#include<random>
#include<algorithm>

using namespace std;

vector<int> Lotto(int sumzs, int sumsj);
void show(const int n);

int main()
{
	vector<int> winners;
	winners = Lotto(51, 6);
	cout << "���ѡ���Բ������ӷֱ�Ϊ��";
	for (auto x : winners)
	{
		cout << x << " ";
	}
	cout << endl;





	system("pause");
	return 0;
}



vector<int> Lotto(int sumzs, int sumsj)
{
	vector<int> temp;
	for (int i = 1; i <= sumzs; i++)
	{
		temp.push_back(i);
	}

	random_device rd;
	mt19937 gen(rd());

	

	vector<int> temp1;
	for (int i = 0; i < sumsj; i++)
	{
		shuffle(temp.begin(), temp.end(), gen);
		temp1.push_back(temp[0]);
		temp.erase(temp.begin());//ͷ��ɾ����ʹ�������е�Ԫ�ض���ǰ�ƶ�һ��λ�ã�pop.back()�ȽϺ�
		//cout << "ѡ���� " << i + 1 << " ��Բ���ʣ��" << temp.size() << " ��Բ��!" << endl;
		//cout << "�ֱ��ǣ�" << endl;
		//for_each(temp.begin(), temp.end(), show);
		//cout << endl;

	}



	return temp1;
}


void show(const int n)
{

	cout << n << " ";

}