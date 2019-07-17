

#include<iostream>

using namespace std;

#pragma pack(1)

class Person
{
public:
	int m_A;//非静态成员变量，属于对象上

	void func(/*Person * this*/){}; //非静态成员函数 不属于对象身上

	static int  m_B;//静态成员函数，不属于对象上

	static void fun2(){};//静态成员函数 ，不属于对象身上

	//double m_C;//12错误 16正确,解决方法#pragma pack(1)
};

//结论：非静态成员变量，才属于对象身上

void test01()
{
	cout << "Person类的大小：" << sizeof(Person) << endl;
	//空类的大小为1 每个实例的对象 都有独一无二的地址，char维护这个地址
	//Person p[10] p[0] p[1]
}

void test02()
{

	//this指针指向被调用的成员函数
	Person p1;
	p1.func(); //编译器会偷偷 加入一个this指针 Person * this 

	Person p2;
	p2.func();
}

int main()
{
	test01();
	system("pause");
	return 0;
}