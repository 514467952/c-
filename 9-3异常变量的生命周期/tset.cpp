
#include<iostream>

using namespace std;

class myException
{
public:
	myException()
	{
		cout << "myException��Ĭ�Ϲ���" << endl;
	}
	myException(const myException&e)
	{
		cout << "myException�Ŀ�������" << endl;
	}

	~myException()
	{
		cout << "myException����������" << endl;
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
	catch (myException *e)//myException e��࿪��һ������
	{
		//e->prtintError();
		//e->prtintError();
		//e->prtintError();//ָ��Ƿ��ڴ�ռ䣬��Ӧ����ô��
		cout << "�����쳣" << endl;
		//delete e; //���Ծ��ͷŶ���
	}

	
	
}

int  main()
{

	test01();
	system("pause");
	return 0;
}