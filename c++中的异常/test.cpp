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
		//һ������ռ�ʧ��ʱ,longjmp����ת��buff��Ӧ��λ�á�
		longjmp(buff,1);
	}
	///��������
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
	//setjmp����longjmp��������ת��
	//ע��:setjmp���״ε���ʱ��һ���᷵��0
	int iState = setjmp(buff);
	if (0 == iState)
	{
		//��������
		Test1();
		Test2();
	}
	else{
		//���������Ƿ������longjmp��ת��switch
		//һ�����:д�ĳ���Ĵ�����
		switch (iState)
		{
		case 1:
			cout << "malloc����ռ�ʧ��" << endl;
			break;
		case 2:
			cout << "���ļ�ʧ��" << endl;
			break;
		default:
			cout << "δ֪����" << endl;
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
	//���г�����ļ�����
	fclose(pf);
}
void Test2()
{
	char* p = (char*)malloc(0x7ffffffff);
	if (nullptr == p)
	{
		throw 1.0;
	}
	///��������
}
int main()
{
	try
	{
		
		Test2();
		Test();
	}
	//�쳣�������Ͳ���һ�㲻���������ת����
	catch (int e)
	{
		//��������int���͵��쳣
		//����������
		cout << e << endl;
	}
	catch (double e)
	{
		//����double���͵��쳣
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
	//�����쳣ʱ�������ǽ�a�����׳��������׳���a��һ������
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
	//�����쳣ʱ�������ǽ�a�����׳�
	throw a;//ʵ���׵���a�ø���
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
	catch (...)//���ܲ���
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
	int *p = new int[10];//new Ҳ�����쳣��operator new����ռ�ʧ�ܣ����û����Ӧ�Ĵ�ʩ�����쳣
	//....
	try{
		Test();
	}
	catch (...)
	{
		//1.����Test2���ڸ�����֪��Test1�׳��쳣������
		//2.���Test2֪��Test1�����쳣�����ͣ�����Test2û�б�Ҫ����Ҫ���Test1�׳����쳣
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

//Test()���쳣��ֻ���׳����͵��쳣
//����:�ڱ����ڼ�ͻᱨ��
void Test1()throw(int)
{
	throw 1.0;
}
//�ú���һ�������׳��쳣��
//����:�ڱ����ڼ�ͻᱨ��
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
//ͨ�����紫������
void Test1()
{
	NetException e("�����ж�", 40);
	throw e;
}
//�������ݿ�
void Test2()
{
	DBException e("���ݿ�δ��", 500);

}
int main()
{
	try
	{
		Test1();
		Test2();
	}
	catch (Exception&e)//���ջ���ķ�ʽ���в���
	{
		e.What();
	}
	catch (exception&e)
	{
		e.what();
	}
	catch (...)
	{
		cout << "δ֪�쳣" << endl;
	}
	system("pause");
	return 0;
}
