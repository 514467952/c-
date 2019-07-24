
#include<iostream>

using namespace std;

class Base
{
public:
	Base()
	{
		cout << "Base默认构造函数调用" << endl;
	}
	~Base()
	{
		cout << "Base的析构函数的调用" << endl;
	}


};
//子类会继承父类的成员属性，成员属性
//但是 子类 不会继承 父类 构造函数 和 析构函数
//只有父类自己知道如果构造和析构自己的属性，而子类不知道

class Son :public Base
{
public:
	Son()
	{
		cout << "Son默认构造函数的调用" << endl;
	}
	~Son()
	{
		cout << "Son的析构函数的调用" << endl;
	}
};

class Base2
{
public:
	Base2(int a)
	{
		this->m_A = a;
		cout << "有参构造函数调用" << endl;
	}

	int  m_A;
};

class Son2 :public Base2
{
public:
	Son2(int a)	: Base2(10)	//利用初始化列表方式 显示调用 有参构造
	{

	}
};

void test02()
{
	Son2 s2(1000);
}

void test01()
{
	//Base b1;

	Son s1;
}

int main()
{

	test01();
	system("pause");
	return 0;
}