
#include<iostream>

using namespace std;

class myException
{
public:
	myException()
	{
		cout << "myException的默认构造" << endl;
	}
	myException(const myException&e)
	{
		cout << "myException的拷贝构造" << endl;
	}

	~myException()
	{
		cout << "myException的析构调用" << endl;
	}

	void prtintError()
	{
		m_A = 100;
		cout << "error" <<this->m_A << endl;
	}

	int m_A;
};

void doWork()
{
	throw & myException();

}

void test01()
{
	try
	{
		doWork();
	}
	catch (myException *e)//myException e会多开销一份数据
	{
		//e->prtintError();
		//e->prtintError();
		//e->prtintError();//指向非法内存空间，不应该这么做
		cout << "捕获异常" << endl;
		//delete e; //靠自觉释放对象
	}

	
	
}

int  main()
{

	test01();
	system("pause");
	return 0;
}