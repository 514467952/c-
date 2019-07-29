
#include<iostream>

using namespace std;

//异常基类
class BaseException
{
public:
	virtual void printError()
	{

	}
};

class NullPointerException : public BaseException
{
public:
	virtual void printError()
	{
		cout << "空指针异常" << endl;
	}
};

class OutofRangeExcrption : public BaseException
{
public:
	virtual void printError()
	{
		cout << "越界异常" << endl;
	}
};

void doWork()
{
	//throw..
	//throw NullPointerException();
	throw OutofRangeExcrption();
}

void test01()
{
	try
	{
		doWork();
	}
	catch (BaseException  &e)
	{
		e.printError();
	}
}


int main()
{
	test01();

	system("pause");
	return 0;
}