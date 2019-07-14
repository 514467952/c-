#include<iostream>

using namespace std;

class Person
{

public:
	Person()
	{
		cout << "默认的构造函数调用" << endl;

	}
	Person(int a)
	{
		cout << "有参构造函数调用"<<endl;
	}

	Person(const Person &p)
	{
		m_Age = p.m_Age;
		cout << "拷贝构造函数调用" << endl;
	}
	~Person()
	{

		cout << "析构函数" << endl;
	}
	int m_Age;

};

//拷贝构造调用的时机
//1.用已经创建好的对象来初始化新的对象

void test01()
{
	Person p1;
	p1.m_Age = 10;
	Person p2(p1);
}
//2.以值传递的方式给函数参数传值
void doWork(Person p1)		//Person p1=Person(p)
{

}
void test02()
{
	Person p;
	p.m_Age = 10;

	doWork(p);
}

//3.以值得方式返回局部对象
Person doWork2()
{
	Person p1;
	return p1;
}

void test03()
{
	Person p=doWork2();
}
//Release 下优化成什么样？
/* Person p; 不调用默认构造
	doWork2(p);

	void doWork(Person &p)
	{
		Person p1;//调用默认构造
	}
*/

int main()
{
	//test01();
	//test02();
	test03();
	system("pause");
	return 0;
}