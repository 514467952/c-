#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

#if 0
int main()
{
	FILE* pf = fopen("2222.txt", "rb");
	if (nullptr == pf)
	{
		return 0;
	}
	//...
	fclose(pf);
	system("pause");
	return 0;
}
#endif
#if 0
int main()
{
	https://www.baidu.com;
	return 0;
}
#endif
#if 0
#include<malloc.h>
#include<setjmp.h>
jmp_buf buff;
void Test1()
{
	char* p = (char*)malloc(0x7ffffffff);
	if (nullptr == p)
	{
		//一但申请空间失败时,longjmp会跳转到buff对应的位置。
		longjmp(buff,1);
	}
	///正常操作
}
void Test2()
{
	FILE* pf = fopen("2222.txt", "rb");
	if (nullptr == pf)
	{
		longjmp(buff, 2);
	}
	//...
	fclose(pf);
}
int main()
{
	//setjmp设置longjmp函数的跳转点
	//注意:setjmp在首次调用时，一定会返回0
	int iState = setjmp(buff);
	if (0 == iState)
	{
		//正常操作
		Test1();
		Test2();
	}
	else{
		//程序遇到非法情况，longjmp跳转到switch
		//一般情况:写的程序的错误处理
		switch (iState)
		{
		case 1:
			cout << "malloc申请空间失败" << endl;
			break;
		case 2:
			cout << "打开文件失败" << endl;
			break;
		default:
			cout << "未知错误" << endl;
			break;
		}
	}
	return 0;
}
#endif
#if 0
void Test()
{
	FILE* pf = fopen("2222.txt", "rb");
	if (nullptr == pf)
	{
		throw 1;
	}
	//...
	//进行常规的文件操作
	fclose(pf);
}
void Test2()
{
	char* p = (char*)malloc(0x7ffffffff);
	if (nullptr == p)
	{
		throw 1.0;
	}
	///正常操作
}
int main()
{
	try
	{
		
		Test2();
		Test();
	}
	//异常按照类型捕获，一般不会进行类型转换的
	catch (int e)
	{
		//捕获所有int类型的异常
		//错误处理流程
		cout << e << endl;
	}
	catch (double e)
	{
		//捕获double类型的异常
		cout << e << endl;
	}
	system("pause");
	return 0;
}
#endif
#if 0
void Test()
{
	FILE* pf = fopen("2222.txt", "rb");
	if (nullptr == pf)
	{
		throw 1;
	}
	//...
	fclose(pf);
}
void Test2()
{
	int *p = new int[10];
	//....
	try{
		Test();
	}
	catch (int e)
	{
		delete[]p;
		cout << e << endl;
		return;
	}
	
}
int main()
{
	try
	{
		Test();
		Test2();
	}
	catch (int e)
	{
		cout << e << endl;
	}
	system("pause");
	return 0;
}
#endif
#if 0
void Test()
{
	int a = 10;
	cout << &a << endl;
	//在抛异常时，并不是将a本身抛出，而是抛出了a的一个副本
	throw a;
}
int main()
{
	try
	{
		Test();
	}
	catch (int& ra)
	{
		cout << &ra << endl;
	}
	system("pause");
	return 0;
}
#endif
#if 0
class A
{
public:
	A()
	{
		cout << "A::A()" << this << endl;
	}
	A(const A&a)
	{
		cout << "A::A(const A&a)" << this<<endl;
	}
	~A()
	{
		cout << "A::~A()" << this << endl;
	}
};

void Test()
{
	A a;
	cout << &a << endl;
	//在抛异常时，并不是将a本身抛出
	throw a;//实际抛得是a得副本
}
int main()
{
	try
	{
		Test();
	}
	/*catch (A& ra)
	{
		cout << &ra << endl;
	}*/
	catch (...)//万能捕获
	{
		cout << "A" << endl;
	}
	system("pause");
	return 0;
}
#endif
#if 0
void Test()
{
	FILE* pf = fopen("2222.txt", "rb");
	if (nullptr == pf)
	{
		throw 1;
	}
	//...
	fclose(pf);
}
void Test2()
{
	int *p = new int[10];//new 也会抛异常，operator new申请空间失败，如果没有相应的措施，抛异常
	//....
	try{
		Test();
	}
	catch (...)
	{
		//1.假设Test2现在根本不知道Test1抛出异常的类型
		//2.如果Test2知道Test1所抛异常的类型，但是Test2没有必要必须要解决Test1抛出的异常
		delete[]p;
		throw ;
	}
	delete[]p;
}
int main()
{
	try
	{
		Test2();
	}
	catch (int e)
	{
		cout << e << endl;
	}
	system("pause");
	return 0;
}
#endif
#if 0
void Test()
{
	throw;
}
int main()
{
	Test();
	return 0;
}
#endif

//Test()抛异常，只能抛出整型的异常
//否则:在编译期间就会报错
void Test1()throw(int)
{
	throw 1.0;
}
//该函数一定不会抛出异常，
//否则:在编译期间就会报错
void Test2()throw()
{
}

class Exception
{
public:
	Exception(const string& errInfo,int errNo)
		:_errInfo(errInfo)
		, _errNo(errNo)
	{}
	virtual void What() = 0;
protected:
	string _errInfo;
	int _errNo;
};
class NetException : public Exception
{
public:
	NetException(const string& errInfo, int errNo)
		:Exception(errInfo,errNo)
	{}
	virtual void What()
	{
		cout << _errInfo << ":" << _errNo << endl;
	}
};
class DBException : public Exception
{
public:
	DBException(const string& errInfo, int errNo)
		:Exception(errInfo, errNo)
	{}
	virtual void What()
	{
		cout << _errInfo << ":" << _errNo << endl;
	}
};
//通过网络传递数据
void Test1()
{
	NetException e("网络中断", 40);
	throw e;
}
//操作数据库
void Test2()
{
	DBException e("数据库未打开", 500);

}
int main()
{
	try
	{
		Test1();
		Test2();
	}
	catch (Exception&e)//按照基类的方式进行捕获
	{
		e.What();
	}
	catch (exception&e)
	{
		e.what();
	}
	catch (...)
	{
		cout << "未知异常" << endl;
	}
	system("pause");
	return 0;
}
