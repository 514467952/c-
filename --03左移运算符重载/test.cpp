
#include<iostream>

using namespace std;

class Person
{
	friend ostream & operator <<(ostream &cout, Person&p1);
public:
	Person(){}

	Person(int a, int b)
	{
		this->m_A = a;
		this->m_B = b;
	}

	/*void operator<<() 重载左移运算符不可以写到成员函数中
	{

	}*/

private:
	int m_A;
	int m_B;

};
//cout是属于ostream类 
//如果向访问私有成员，就要用友元函数
ostream & operator <<(ostream &cout, Person&p1) //第一个参数cout 第二个参数p1
{
	cout << "m_A=" << p1.m_A << "m_B=" << p1.m_B;
	return cout;
}

void test01()
{
	Person p1(10, 10);
	cout << p1<<endl;
}

int main()
{
	test01();
	system("pause");
	return 0;
}