
#include<iostream>

using namespace std;

#include<string>
using namespace std;

//系统提供标准异常
#include<stdexcept>


class MyOutofRangeException :public exception
{
public:
	MyOutofRangeException(string errorInfo)
	{
		this->m_ErrorInfo = errorInfo;
	}
	virtual ~MyOutofRangeException()
	{

	}
	virtual const char *what()const
	{
		//返回 错误信息
		//string 转 char *     .c_str()
		return this->m_ErrorInfo.c_str();

	}


	string m_ErrorInfo;
};


class Person
{
public:
	Person(string name, int age)
	{
		this->m_Name = name;
		//年龄做检测

		if (age<0 || age>200)
		{
			throw MyOutofRangeException(string ("我自己的年龄越界异常"));
		}
	}

	string m_Name;
	int m_Age;
};

void test01()
{
	try
	{
		Person p("张三", 300);
	}
	catch (MyOutofRangeException &e)
	{
		cout << e.what() << endl;
	}
	
}


int main()
{
	test01();
	system("pause");
	return 0;
}