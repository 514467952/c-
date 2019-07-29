
#include<iostream>

using namespace std;


class myException  //自定义异常类
{
public:
	void printError()
	{
		cout << "自定义的异常" << endl;
	}
};
class Person
{
public:
	Person()
	{
		cout << "Person构造" << endl;

	}
	~Person()
	{
		cout << "Person析构" << endl;
	}
};


int myDevide(int a, int b)
{
	if (b == 0)
	{
		//如果b是异常，抛出异常
		//return -1;
		//throw - 1; 抛出int类型异常
		//throw 3.14;//抛出double类型异常   异常必须处理
		//throw 'a';


		//栈解旋
		//从try开始到throw抛出异常之前，所有栈上的对象都会被释放
		//这个过程称为栈解旋
		//构造析构顺序相反

		Person p1;
		Person p2;



		throw myException(); //匿名对象
	}
	return a / b;
}


void test01()

{
	int a = 10;
	int b = 0;
	//int ret = myDevide(a, b);//早期如果返回-1 无法区分到底是结果还是异常

	//c++中异常处理
	try
	{
		myDevide(a, b);
	}
	catch (int)//捕获异常
	{
		cout << "int 类型异常捕获" << endl;
	}
	catch (double)
	{
		//如果不想处理这个异常，可以向继续向上抛出
		throw;
		cout << "double类型异常捕获" << endl;
	}

	catch (myException e)
	{
		e.printError();
	}

	catch (...)
	{
		cout << "其他异常类型捕获" << endl;
	}

}





int main()
{
	try
	{
		test01();
	}
	catch (double) //如果异常都没处理，那么成员terminate函数，使程序中断
	{
		cout << "main函数中double类型异常捕获" << endl;
	}
	catch (...)
	{
		cout << "main函数中其他异常类型捕获" << endl;
	}

	//test01();
	system("pause");
	return 0;
}