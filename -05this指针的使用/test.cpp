

#include<iostream>

using namespace std;

// this ���Խ��������ͻ

class Person
{
public:
	Person(int age)
	{
		this->age = age;
	}

	//�Ա�����
	void compareAge(Person &p)
	{
		if (this->age == p.age)
		{
			cout << "���" << endl;
		}
		else
		{
			cout << "�����" << endl;
		}
	}

	//�������
	Person&  PlusAge(Person &p)
	{
		this->age += age;
		return *this;  //*thisָ�����ı���
	}

	int age;
};

void test01()
{
	Person p1(10);

	cout << "p1������" << p1.age << endl;

	Person p2(10);

	p1.compareAge(p2);

	p1.PlusAge(p2).PlusAge(p2);//��ʽ���
	//��������ֵ��Ϊ��ֵ ��������
	cout << "p1������" << p1.age << endl;
}


int main()
{
	test01();
	system("pause");
	return 0;
}