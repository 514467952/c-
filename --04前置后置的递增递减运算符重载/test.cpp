
#include<iostream>

using namespace std;

class MyInteger
{
	friend ostream & operator<<(ostream &cout, MyInteger& myInt);
	
public:
	MyInteger()
	{
		m_Num = 0;
	}
	//前置++重载
	//返回引用 ++(++a)
	MyInteger & operator++()
	{
		this->m_Num++;
		return *this;
	}
	//用占位参数区分前置和后置
	//后置++重载
	//返回值，
	MyInteger operator++(int)
	{
		//先保存目前的数据
		MyInteger tmp = *this;
		//实际数据++
		m_Num++;
		//返回++前的数值
		return tmp;
	}
	//所以前置++好，因为返回引用，少一份开销

	int m_Num;
};

ostream & operator<<(ostream &cout, MyInteger& myInt)
{
	cout << myInt.m_Num;
	return cout;
}

void test01()
{
	MyInteger myInt;

	//前置++值
	cout << ++myInt << endl;
	//后置++值
	cout << myInt++ << endl;
	//本身的值
	cout << myInt << endl;
}

int main()
{

	test01();
	system("pause");
	return 0;
}