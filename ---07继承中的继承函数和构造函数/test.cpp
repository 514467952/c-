
#include<iostream>

using namespace std;

class Base
{
public:
	Base()
	{
		cout << "BaseĬ�Ϲ��캯������" << endl;
	}
	~Base()
	{
		cout << "Base�����������ĵ���" << endl;
	}


};
//�����̳и���ĳ�Ա���ԣ���Ա����
//���� ���� ����̳� ���� ���캯�� �� ��������
//ֻ�и����Լ�֪���������������Լ������ԣ������಻֪��

class Son :public Base
{
public:
	Son()
	{
		cout << "SonĬ�Ϲ��캯���ĵ���" << endl;
	}
	~Son()
	{
		cout << "Son�����������ĵ���" << endl;
	}
};

class Base2
{
public:
	Base2(int a)
	{
		this->m_A = a;
		cout << "�вι��캯������" << endl;
	}

	int  m_A;
};

class Son2 :public Base2
{
public:
	Son2(int a)	: Base2(10)	//���ó�ʼ���б�ʽ ��ʾ���� �вι���
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