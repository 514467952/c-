
#include<iostream>

using namespace std;

class Person
{
public:
	//Person(){}
	Person(int age)
	{
		this->m_Age = age;
	}

	void showAge()
	{
		cout << "����Ϊ��" << this->m_Age << endl;
	}
	~Person()
	{
		cout << "Peson����������" << endl;
	}

	int m_Age;

};
//����ָ��
//�����й��Զ������Ͷ����ö�������Զ����ͷ�
class smartPointer
{
public:
	smartPointer(Person *person)
	{
		this->person = person;
	}

	//����->������ָ�������Person * pһ��ȥʹ��
	Person * operator->()
	{
		return this->person;
	}

	//���� *
	Person & operator*()
	{
		return *this->person;
	}

	~smartPointer()
	{
		cout << "����ָ��������" << endl;
		if (this->person== NULL)
		{
			delete this->person;
			this->person = NULL;
		}
	}

private:
	Person * person;
};

void test01()
{
	//Person p1(10); //������ջ�� ���Զ�����

	//Person *p1 = new Person(10);	//�����ڶ��ϣ���Ҫ�ֶ��ͷ�

	//delete p1;
	smartPointer sp(new Person(10));//sp���ٵ���ջ�ϣ��Զ��ͷ�
	(*sp).showAge();//sp->->showAge(); �������Ż���
}


int main()
{
	test01();
	system("pause");
	return 0;

}