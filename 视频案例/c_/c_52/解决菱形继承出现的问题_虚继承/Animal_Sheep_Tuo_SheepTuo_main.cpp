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
	//虚继承解决菱形继承造成的资源浪费
	//无论怎么初始化，始终只有一份数据
	SheepTuo st;
	
	
	
	st.Sheep::m_Age = 18;
	st.Tuo::m_Age = 28;
	cout << "通过Sheep访问m_Age: " << st.Sheep::m_Age << endl;
	cout << "通过Tuo访问m_Age: " << st.Tuo::m_Age << endl;
	cout << "通过Animal访问m_Age: " << st.Animal::m_Age << endl;



	//st.Sheep::Animal::m_Age = 18;//效果与上面一样
	//st.Tuo::Animal::m_Age = 28;
	//cout << "通过Sheep访问m_Age: " << st.Sheep::Animal::m_Age << endl;
	//cout << "通过Tuo访问m_Age: " << st.Tuo::Animal::m_Age << endl;

	st.Animal::m_Age = 38;//虚继承解决了 会先创建Animal类，导致出现问题
	cout << "通过Animal访问m_Age: " << st.Animal::m_Age << endl;
	cout << "通过Sheep访问m_Age: " << st.Sheep::m_Age << endl;
	cout << "通过Tuo访问m_Age: " << st.Tuo::m_Age << endl;
	
	st.m_Age = 58;//可以直接用对象 不加类名作用域访问m_Age
	cout << "通过Sheep访问m_Age: " << st.Sheep::m_Age << endl;
	cout << "通过Tuo访问m_Age: " << st.Tuo::m_Age << endl;
	cout << "通过Animal访问m_Age: " << st.Animal::m_Age << endl;


	
}

