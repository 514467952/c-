
#include<iostream>

using namespace std;

template<class T>
class Base
{
public:
	T m_A;

};

//Child�̳���Base�������base�е�T�����ͣ�����T�޷������ڴ�
class Child :public Base<int>
{

};

//Child2Ҳ��ģ����
template<class T1,class T2>
class Child2 :public Base<int>
{
public:
	Child2()
	{
		cout << typeid(T1).name ()<< endl;
		cout << typeid(T2).name ()<< endl;
	}
public:
	T1 m_B;
};

void test01()
{
	Child2<int, double >child;//���û���ָ������
}

int main()
{
	test01();
	system("pause");
	return 0;
}
