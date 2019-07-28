
#include<iostream>

using namespace std;

template<class T>
class Base
{
public:
	T m_A;

};

//Child继承于Base必须告诉base中的T的类型，否则T无法分配内存
class Child :public Base<int>
{

};

//Child2也是模板类
template<class T1,class T2>
class Child2 :public Base<int>
{
public:
	Child2()
	{
		cout << typeid(T1).name ()<< endl;
		cout << typeid(T2).name ()<< endl;
	}
public:
	T1 m_B;
};

void test01()
{
	Child2<int, double >child;//由用户来指定类型
}

int main()
{
	test01();
	system("pause");
	return 0;
}
