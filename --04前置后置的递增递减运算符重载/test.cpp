
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
	//ǰ��++����
	//�������� ++(++a)
	MyInteger & operator++()
	{
		this->m_Num++;
		return *this;
	}
	//��ռλ��������ǰ�úͺ���
	//����++����
	//����ֵ��
	MyInteger operator++(int)
	{
		//�ȱ���Ŀǰ������
		MyInteger tmp = *this;
		//ʵ������++
		m_Num++;
		//����++ǰ����ֵ
		return tmp;
	}
	//����ǰ��++�ã���Ϊ�������ã���һ�ݿ���

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

	//ǰ��++ֵ
	cout << ++myInt << endl;
	//����++ֵ
	cout << myInt++ << endl;
	//�����ֵ
	cout << myInt << endl;
}

int main()
{

	test01();
	system("pause");
	return 0;
}