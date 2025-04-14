#include<iostream>
#include<string>
#include"Animal.h"
#include"Sheep.h"
#include"Tuo.h"
#include"SheepTuo.h"
using namespace std;
void test01();




int main()
{
	test01();


	system("pause");
	return 0;
}

void test01()
{
	SheepTuo st;
	
	
	
	st.Sheep::m_Age = 18;
	st.Tuo::m_Age = 28;
	cout << "通过Sheep访问m_Age: " << st.Sheep::m_Age << endl;
	cout << "通过Tuo访问m_Age: " << st.Tuo::m_Age << endl;



	//st.Sheep::Animal::m_Age = 18;//效果与上面一样
	//st.Tuo::Animal::m_Age = 28;
	//cout << "通过Sheep访问m_Age: " << st.Sheep::Animal::m_Age << endl;
	//cout << "通过Tuo访问m_Age: " << st.Tuo::Animal::m_Age << endl;

	//st.Animal::m_Age = 38;//会先创建Animal类，导致出现问题
	//cout << "通过Animal访问m_Age: " << st.Animal::m_Age << endl;
	
	

	
}

