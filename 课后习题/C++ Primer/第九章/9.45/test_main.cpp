#include<iostream>
#include<vector>
#include<string>
#include<iterator>
#include<cstddef>
#include<list>
#include<deque>
#include<forward_list>





using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::vector;
using std::string;
using std::begin;
using std::end;
using std::size_t;
using std::list;
using std::deque;
using std::forward_list;



const string& func_str(string& name, const string& fr, const string& la);


int main()
{
	string name_aa = "aaa";
	string name_bb = "bbb";
	string fr_aa = "Mr";
	string la_aa = "Jr";
	string name_aa_fr_la = func_str(name_aa, fr_aa, la_aa);
	string name_aa_fr_la1 = func_str(name_bb, "Mrs", "III");



	cout << name_aa_fr_la << endl;
	cout << name_aa_fr_la1 << endl;



	system("pause");
	return 0;
}


const string& func_str(string& name, const string& fr, const string& la)
{
	//name.insert(name.begin(), fr.begin(),fr.end());
	name.insert(name.begin(), 1, ' ');
	
	//return name.append(la);
	return name.insert(0, fr).append(" ").append(la);


}












